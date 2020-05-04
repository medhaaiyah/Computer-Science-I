/*Assignment 2 for CS 1337.013
 *Programmer: Medha Aiyah
 *Description: This file is used to program the constructors, destructors, and the member functions for the Question
 *             class and the Trivia Game class.
 */
#include <iostream>
#include "assignment2.h"
using namespace std;

//This Question constructor is used to initialize the question, possible answers, and the correct number for the answer

Question::Question()
{
    questionTxt = "";
    for(int i=0; i < MAX_SIZE; i++)
    {
        possibleAnswers[i] = "";
    }
    answerCorrectNum = 0;
}

//This question constructor will get the question text, the 4 possible answers, and the answer number of the correct answer

Question::Question(fstream &file)
{
    getline(file, questionTxt, '\n');
    for(int i=0; i < MAX_SIZE; i++)
    {
        getline(file, possibleAnswers[i],'\n');
        numPossibleAns++;
    }
    file.clear();
    file >> answerCorrectNum;
    file.ignore(100, '\n');

}

//The Question destructor will set the variables used in the constructor to null or zero values

Question::~Question()
{
    questionTxt = "";
    for(int i=0; i < MAX_SIZE; i++)
    {
        possibleAnswers[i] = "";
    }
    answerCorrectNum = 0;

}

//This function is used to return the number of the possible answers available

unsigned int Question::numPossibleAnswers() const
{
    return numPossibleAns;
}

//This function is used to return the correct answer number for the specific question

unsigned int Question::numCorrectAnswers() const
{
    return answerCorrectNum;
}

//This function is used to return the text of the question

string Question::questionText() const
{
    return questionTxt;
}

//This function is used to return the text for the 4 possible answers

string Question::answerText(unsigned int choice) const
{
    return possibleAnswers[choice];
}

//This constructor is supposed to read in the input file and build all of the questions based on the information in
//the input file.

TriviaGame::TriviaGame(fstream &file)
{
    //This is what will happen if the file is unable to open

    if (file.fail())
    {
        cout << "This file is unable to open." << endl;
    }

    //If the file successfully opens, it will access the ptr and it will store the question, possible answers, and the
    //correct answer that was stored in the Question constructor.

    else
    {
        file >> numQuestion;
        cout << "This is the number of questions." << numQuestion << endl;
        index1 = 0;
        index2 = numQuestion / 2;
        file.ignore(100, '\n');
        ptr = new Question[numQuestion];
        for (int i =0; i < numQuestion; i++)
        {
            ptr[i] = Question(file);
        }
    }
}

//This destructor is used to delete values in the array

TriviaGame::~TriviaGame()
{
    delete [] ptr;
}

//This function is used to return the number of questions

unsigned int TriviaGame::numOfQuestions()
{
    return numQuestion;
}

//This function is created to return the next question for a given player
//This should return a const reference to the next Question object for the given player

const Question & TriviaGame::nextQuestionPlayer1()
{
    return ptr[index1++];
}
const Question & TriviaGame::nextQuestionPlayer2()
{
    return ptr[index2++];
}

//This function is used to validate whether or not player one put down the right answer

bool TriviaGame::correctAnswerPlayer1(Question question, unsigned int answerPlayer1)
{

    if (answerPlayer1 == question.numCorrectAnswers()) //the user answer is equal to the right answer of the question
    {
        validityPlayer1 = true;
    }
    else
    {
        validityPlayer1 = false;
    }
    return validityPlayer1;
}

//This function is used to validate whether or not player two put down the right answer

bool TriviaGame::correctAnswerPlayer2(Question question, unsigned int answerPlayer2)
{
    if (answerPlayer2 == question.numCorrectAnswers()) //the user answer is equal to the right answer of the question
    {
        validityPlayer2 = true;
    }
    else
    {
        validityPlayer2 = false;
    }
    return validityPlayer2;
}

//This function is used to increment the points for player 1

void TriviaGame::additionPointsPlayer1()
{
    if(validityPlayer1)
    {
        pointsPlayer1++;
    }
}

//This function is used to increment the points for player 2

void TriviaGame::additionPointsPlayer2()
{
    if(validityPlayer2)
    {
        pointsPlayer2++;
    }
}
