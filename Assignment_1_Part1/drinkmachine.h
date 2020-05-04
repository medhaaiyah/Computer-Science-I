/*
 * drinkmachine.h
 *This is the header file for Assignment 1 Part 1
 */

#ifndef DRINKMACHINE_H_
#define DRINKMACHINE_H_

// put any includes here
#include <iostream>
#include <fstream>
#include <iomanip>

//put constant structures
const unsigned int MAX_DRINKS = 20;

// put your structures here
struct DrinkItem
{
    unsigned int id;
    std::string name;
    double price;
    unsigned int numOfDrinks;
    unsigned int drinksPurchased;
};
struct DrinkMachine
{
    unsigned int versionNum;
    unsigned int drinkItem;
    DrinkItem drinks[MAX_DRINKS];
};

// put function prototypes here
bool create(DrinkMachine &drinkMachine); //create function COMPLETED
void destroy(DrinkMachine &drinkMachine); // destroy function COMPLETED
DrinkItem& drink(DrinkMachine &drinkMachine, unsigned int drinkId); //drink function COMPLETED
unsigned int size(DrinkMachine &drinkMachine); //size function COMPLETED
bool available(DrinkMachine &drinkMachine, unsigned int drinkId); //available function COMPLETED
double price(DrinkMachine &drinkMachine, unsigned int drinkId); //price function COMPLETED
std::string name(DrinkMachine &drinkMachine, unsigned int drinkId); //name function COMPLETED
unsigned int quantity(DrinkMachine &drinkMachine, unsigned int drinkId); //quantity function COMPLETED
unsigned int sold(DrinkMachine &drinkMachine, unsigned int drinkId); //sold function COMPLETED
bool purchase(DrinkMachine &drinkMachine, int unsigned drinkId, double amount, double &change); //purchase function COMPLETED
void dumpDrinkMachine(const DrinkMachine &drinkMachine); //dumpDrinkMachine function COMPLETED
void bubbleSort(DrinkMachine &drinkMachine, int size);



// put all of your includes, structures and prototypes before this comment
#endif /* DRINKMACHINE_H_ */