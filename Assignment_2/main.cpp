/*
 * Assignment 2 Main Function for CS 1337
 * Programmer: Medha Aiyah
 * Description: This main function is used to display the question and the possible answers for each trivia question for
 *              the user to answer. The main function should also determine the winner and output the number of points
 *              for each player along with their specific means. It should also print out the game's mean as well.
 *
 */

//These are the header files used for this function.

#include <iostream>
#include "assignment2.h"

using namespace std;

int main()
{
    //These are the variables are declared and used in this function.

    Question question;
    unsigned int answerPlayer1;
    unsigned int answerPlayer2;
    fstream inputFile;
    bool playerOne;
    bool playerTwo;
    unsigned int playerOnePoints;
    unsigned int playerTwoPoints;
    double playerOneMean;
    double playerTwoMean;
    double totalMean;

    //The inputFile is opening the triviaGame1.txt file

    inputFile.open("triviaGame1.txt");
    //inputFile.open("triviaGame3.txt");


    //If the input file is unable to open, then it will print the following error message

    if (inputFile.fail())
    {
        cout << "This file is unable to open" << endl;
    }

    //This is what will run if the file successfully opens.

    else
    {

        //Creating a variable game that will be able to access the information from the Trivia Game class

        TriviaGame game(inputFile);

        //This is a brief summary that will be printed out before the questions.

        cout << "This game consists of 2 players, each answering 2 questions." << endl;
        cout << "The player with the most points will win the game." << endl;

        cout << endl;

        //This for loop is used to print out the specific questions for player one and for player 2

        for (unsigned int question = 0; question < game.numOfQuestions() / 2; question++) {

            //qOne and qTwo are used to get the questions and the possible answers for each player and display the questions

            Question qOne = game.nextQuestionPlayer1();
            Question qTwo = game.nextQuestionPlayer2();

            /*----------------This is what will be displayed for player 1----------------*/

            //This is will print out the question for player 1

            cout << "Question # " << (question + 1) << " for player 1" << endl;
            cout << qOne.questionText() << endl;
            cout << endl;

            //This will print out the possible answers for player 1

            cout << "Pick from the following answers:" << endl;
            for (unsigned int j = 0; j < qOne.numPossibleAnswers(); j++) {
                cout << "A # " << (j + 1) << ": " << qOne.answerText(j) << endl;
            }
            cout << endl;

            //This is the prompt for player 1 to enter their answer

            do
            {
                cout << "Enter your answer:" << endl;
                cin >> answerPlayer1;
                if (answerPlayer1 > MAX_SIZE || answerPlayer1 < 1)
                {
                    cout << "This answer number is not valid. Put in a valid answer number." << endl;
                }
            }while(answerPlayer1 > MAX_SIZE || answerPlayer1 < 1);

            playerOne = game.correctAnswerPlayer1(qOne, answerPlayer1);
            cout << endl;

            /*----------------This is what will be displayed for player 2----------------*/

            //This is will print out the question for player 2

            cout << "Question # "  << (question + 1) << " for player 2" << endl;
            cout << qTwo.questionText() << endl;
            cout << endl;

            //This will print out the possible answers for player 2

            cout << "Pick from the following answers:" << endl;
            for (unsigned int j = 0; j < qTwo.numPossibleAnswers(); j++)
            {
                cout << "A # " << (j + 1) << ": " << qTwo.answerText(j) << endl;
            }
            cout << endl;

            //This is the prompt for player 2 to enter their answer

            do
            {
                cout << "Enter your answer:" << endl;
                cin >> answerPlayer2;
                if (answerPlayer2 > MAX_SIZE || answerPlayer2 < 1)
                {
                    cout << "This answer number is not valid. Put in a valid answer number." << endl;
                }
            }while(answerPlayer2 > MAX_SIZE || answerPlayer2 < 1);
            playerTwo = game.correctAnswerPlayer2(qTwo, answerPlayer2);
            cout << endl;

            /*-----------This is going to be used to validate whether it is the correct answer---------*/

            if (playerOne)
            {
                cout << "Player 1 had the correct answer for question 1." << endl;
            }
            else
            {
                cout << "Player 1 had the incorrect answer for question 1." << endl;
            }

            //This is where the appropriate incrementation of points for player 1 will happen

            game.additionPointsPlayer1();

            if (playerTwo)
            {
                cout << "Player 2 had the correct answer for question 1." << endl;
            }
            else
            {
                cout << "Player 2 had the incorrect answer for question 1." << endl;
            }

            //This is where the appropriate incrementation of points for player 2 will happen

            game.additionPointsPlayer2();

            cout << endl;
        }

        /*--------This section is going to determine which player won and their respective means---------*/

        //These variables will display the total points for player 1 and for player 2

        playerOnePoints = game.getPointsPlayer1();
        playerTwoPoints = game.getPointsPlayer2();

        //These variables are calculating the respective means for player 1, player 2, and the total mean

        playerOneMean = (static_cast<double>(playerOnePoints) / (game.numOfQuestions() / 2)) * 100;
        playerTwoMean = (static_cast<double>(playerTwoPoints) / (game.numOfQuestions() / 2)) * 100;
        totalMean = (playerOneMean + playerTwoMean) / 2;

        cout << fixed << setprecision(1);

        //The series of if statements are used to determine which player won, lost, or if there is a tie

        if(playerTwoPoints > playerOnePoints)
        {
            cout << "Player 2 wins with " << playerTwoPoints << " points, player 1 received " << playerOnePoints
                 << " points." << endl;
        }
        if (playerTwoPoints < playerOnePoints)
        {
            cout << "Player 1 wins with " << playerOnePoints << " points, player 2 received " << playerTwoPoints
                 << " points." << endl;
        }
        if (playerTwoPoints == playerOnePoints)
        {
            cout << "There was a tie between the players." << "Player 1 had " << playerOnePoints
                 << " points and player 2 had " << playerTwoPoints << " points." << endl;
        }

        cout << endl;

        //This will print the appropriate means for player 1, player 2, and the total mean.

        cout << "Player 1 mean was " << playerOneMean << "%" << endl;
        cout << "Player 2 mean was " << playerTwoMean << "%" << endl;
        cout << "Game mean was " << totalMean << "%" << endl;
    }
    return 0;
}