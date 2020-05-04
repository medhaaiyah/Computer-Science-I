/*Assignment 1 Part 1 for CS 1337.013
 *Programmer: Medha Aiyah
 *Description: These are the functions that are used to read into the txt file to collect the information needed for the
 *             drink machine. This information is recorded and displayed to make the drink machine work appropriately.
 */
//The header file that is used in this file
#include "drinkmachine.h"
using namespace std;

/*
 * The create function is used to read in the values from the drink_machine.txt file and transfer's the information
 * to the appropriate arrays. This function is returning a boolean variable.
 */
bool create(DrinkMachine &drinkMachine)
{
    //These are the variables used in this function
    ifstream inputFile;
    bool exists;
    //It is opening the appropriate file
    inputFile.open("drink_machine.txt");
    //This is what will happen if the file is unable to open
    if(inputFile.fail())
    {
        exists = false;
    }
    //This is what will happen if it is able to read the file
    else
    {
        inputFile >> drinkMachine.drinkItem;
        for(unsigned int i = 0; i < drinkMachine.drinkItem; i++)
        {
            drinkMachine.drinks[i].id = i + 1;
            inputFile >> drinkMachine.drinks[i].name;
            inputFile >> drinkMachine.drinks[i].price;
            inputFile >> drinkMachine.drinks[i].numOfDrinks;
        }
        exists = true;
        //This sets the version number to 1
        drinkMachine.versionNum = 1;
    }
    //This will close the file and return the boolean variable
    inputFile.close();
    return exists;
}

/*
 * This function writes the contents of the drink machine out to the file and sets the structure size to 0. It does not
 * return any variable.
 */

void destroy(DrinkMachine &drinkMachine)
{
    //This is the variable used in this function
    ofstream outputFile;
    //It opens the file
    outputFile.open("drink_machine.txt");
    //Reading out the contents
    outputFile << drinkMachine.drinkItem << endl;
    for(unsigned int i = 0; i < drinkMachine.drinkItem; i++)
    {
        outputFile << drinkMachine.drinks[i].name << endl;
        outputFile << drinkMachine.drinks[i].price << endl;
        outputFile << drinkMachine.drinks[i].numOfDrinks << endl;
        //drinkMachine.drinks[i].drinksPurchased;

    }
    //This is used to sort out the number of drinks sold in descending order
    bubbleSort(drinkMachine, drinkMachine.drinkItem);
    //This is used to display the drink machine with the sorted number of drinks sold
    dumpDrinkMachine(drinkMachine);
    //Sets the structure size to 0
    drinkMachine.drinkItem = 0;
    //closes the file
    outputFile.close();
}

/*
 *  This function returns a reference to the appropriate entry in the array.
 */

DrinkItem& drink(DrinkMachine &drinkMachine, unsigned int drinkId)
{
    return drinkMachine.drinks[drinkId - 1];

}
/*
 * This function returns an integer value of the size field of the drink machine.
 */
unsigned int size(DrinkMachine &drinkMachine)
{
    unsigned int size;
    size = drinkMachine.drinkItem;
    return size;
}
/*
 * This function is used to check to see if a drink is available. It will return a boolean variable
 */
bool available(DrinkMachine &drinkMachine, unsigned int drinkId)
{
    bool availability;
    //This is when the drink is available
    if (drinkMachine.drinks[drinkId - 1].numOfDrinks > 0)
    {
        availability = true;
    }
    //This is when the drink is not available
    else
    {
        availability = false;
    }
    return availability;
}
/*
 * This function is used to determine the price of a certain drink. It returns a double value
 */
double price(DrinkMachine &drinkMachine, unsigned int drinkId)
{
    double drinkPrice;
    //If the drink ID is valid then it will assign the price
    if (drinkId >= 1)
    {
        drinkPrice = drinkMachine.drinks[drinkId - 1].price;
    }
    //When the drink is not available
    else
    {
        drinkPrice = -1;
    }
    return drinkPrice;
}
/*
 * This function returns the name of a certain drink. It will return a string type.
 */
string name(DrinkMachine &drinkMachine, unsigned int drinkId)
{
    string drinkName;
    //If the drinkID is valid
    if (drinkId >= 1)
    {
        drinkName = drinkMachine.drinks[drinkId - 1].name;
    }
    //If the drinkID is not valid
    else
    {
        drinkName = "Invalid";
    }
    return drinkName;
}
/*
 * This function is used to determine the quantity of a certain drink. It will return an integer variable
 */
unsigned int quantity(DrinkMachine &drinkMachine, unsigned int drinkId)
{
    unsigned int drinkQuantity;
    //If the drink ID is valid
    if (drinkId >= 1)
    {
        drinkQuantity = drinkMachine.drinks[drinkId - 1].numOfDrinks;
    }
    //If the drink ID is not valid
    else
    {
        drinkQuantity = 0;
    }
    return drinkQuantity;
}
/*
 * This function should return the number of drinks sold. It is going to return an integer value
 */
unsigned int sold(DrinkMachine &drinkMachine, unsigned int drinkId)
{
    unsigned int drinkPurchased;
    //If the drink id is valid
    if (drinkId >= 1)
    {
        drinkPurchased = drinkMachine.drinks[drinkId - 1].drinksPurchased;
    }
    //If the drink id is not valid
    else
    {
        drinkPurchased = 0;
    }
    return drinkPurchased;
}
/*
 * The purchase function is used to determine the drink that the user bought and the amount that he paid for the drink.
 * It will return a boolean variable to determine whether or not the person successfully bought the drink.
 */
bool purchase(DrinkMachine &drinkMachine, int unsigned drinkId, double amount, double &change)
{
    bool purchased;
    //This is what will run when the drink ID is valid
    if (drinkId >= 1)
    {
        //Gets the change
        double price = drinkMachine.drinks[drinkId - 1].price;
        change = amount - price;
        //This is what will happen when the amount is greater than or equal to the original price
        if (amount >= drinkMachine.drinks[drinkId - 1].price)
        {
            purchased = true;
            //decrement the quantity
            drinkMachine.drinks[drinkId - 1].numOfDrinks--;
            //increment the purchase count
            drinkMachine.drinks[drinkId - 1].drinksPurchased++;
        }
        //This is what will happen when the purchase is less than the original price
        else
        {
            purchased = false;
        }
    }
    //This is what will happen if the drink is not available
    else
    {
        purchased = false;
    }
    return purchased;
}
/*
 * This function is used to determine the types of drinks, costs, quantity, and the number sold. There is no return
 * value in this function.
 */
void dumpDrinkMachine(const DrinkMachine &drinkMachine)
{
    //Drink Machine version number
    cout << "Drink Machine version number " << drinkMachine.versionNum << endl << endl;
    //Displays the contents of the drinks in the drink machine
    cout << fixed << setprecision(2);
    cout << "Drink Id" << setw(16) << "Drink" << setw(10) << "Cost" << setw(12)
         << "Quantity" << setw(10) << "Sold" << endl;
    //This will display the contents for each type of drink
    for(unsigned int i = 0; i < drinkMachine.drinkItem; i++)
    {
        cout << setw(8) << drinkMachine.drinks[i].id << setw(16)
             << drinkMachine.drinks[i].name << setw(10)
             << drinkMachine.drinks[i].price << setw(12)
             << drinkMachine.drinks[i].numOfDrinks << setw(10)
             << drinkMachine.drinks[i].drinksPurchased;
        cout << endl;
    }
}
/*
 * This function is created to sort out the drinks sold after the user purchases a certain amount of drinks. This
 * function does not have a return type.
 */
void bubbleSort(DrinkMachine &drinkMachine, int size)
{
   int maxElements;
   int index;
   for (maxElements = size - 1; maxElements > 0; maxElements--)
   {
       for (index = 0; index < maxElements; index++)
       {
           if (drinkMachine.drinks[index].drinksPurchased < drinkMachine.drinks[index + 1].drinksPurchased)
           {
               DrinkItem temp = drinkMachine.drinks[index];
               drinkMachine.drinks[index] = drinkMachine.drinks[index + 1];
               drinkMachine.drinks[index + 1] = temp;
           }
       }
   }
}
