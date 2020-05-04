/*Programmer: Medha Aiyah
 * assignment2.h
 *This is the header file for Assignment 2
 */

#ifndef ASSIGNMENT2_H_
#define ASSIGNMENT2_H_

// put any includes here
#include <iostream>
#include <fstream>
#include <iomanip>

//put constant variables

const unsigned int MAX_SIZE = 4; //is this alright creating a const variable

// put your classes here

class Question
{
    private:
        std::string questionTxt;
        std::string possibleAnswers[MAX_SIZE];
        unsigned int numPossibleAns = 0;
        unsigned int answerCorrectNum = 0;
    public:
        Question();//Constructor #1 - Initialization
        Question(std::fstream &file); //Constructor - Getting the info
        ~Question(); //Destructor - Making them null values
        std::string questionText() const;
        std::string answerText(unsigned int choice) const;
        unsigned int numPossibleAnswers() const;
        unsigned int numCorrectAnswers() const;
};

class TriviaGame
{
    private:
        unsigned int numQuestion;
        unsigned int pointsPlayer1 = 0;
        unsigned int pointsPlayer2 = 0;
        bool validityPlayer1;
        bool validityPlayer2;
        Question *ptr;
        unsigned int index1;
        unsigned int index2;
    public:
        TriviaGame(std::fstream &file); //Constructor
        ~TriviaGame(); //Destructor
        unsigned int numOfQuestions();
        const Question & nextQuestionPlayer1();
        const Question & nextQuestionPlayer2();
        bool correctAnswerPlayer1(Question question, unsigned int answerPlayer1);
        bool correctAnswerPlayer2(Question question, unsigned int answerPlayer2);
        void additionPointsPlayer1();
        unsigned int getPointsPlayer1() {return pointsPlayer1;}
        unsigned int getPointsPlayer2() {return pointsPlayer2;}
        void additionPointsPlayer2();
};

// put all of your includes, structures and prototypes before this comment
#endif /* ASSIGNMENT2_H_ */