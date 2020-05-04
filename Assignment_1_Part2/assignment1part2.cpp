/*Assignment 1 Part 2 for CS 1337.013
 *Programmer: Medha Aiyah
 *Description: These are the functions that are used to read into the bin file to collect the information needed for the
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
    //It is opening the appropriate file
    drinkMachine.fileName.open("drink_machine.bin", ios::in | ios::out | ios::binary);
    bool exists;
    //This is what will happen if the file is unable to open
    if(drinkMachine.fileName.fail())
    {
        exists = false;
    }
        //This is what will happen if it is able to read the file
    else
    {
        char name[16];
        drinkMachine.fileName.read((char*)&drinkMachine.drinkItem, 4);
        cout << drinkMachine.drinkItem << endl;
        for(unsigned int i = 0; i < drinkMachine.drinkItem; i++)
        {
            //Reading the information from the binary file to the arrays
            drinkMachine.drinks[i].id = i + 1;
            drinkMachine.fileName.read(name, 16);
            drinkMachine.drinks[i].name = name;
            drinkMachine.fileName.read((char*)&drinkMachine.drinks[i].price, 8);
            drinkMachine.fileName.read((char*)&drinkMachine.drinks[i].numOfDrinks, 4);
            drinkMachine.fileName.read((char*)&drinkMachine.drinks[i].drinksPurchased, 4);
            drinkMachine.drinks[i].quantityOffset = (28 +(i * 32));
            drinkMachine.drinks[i].soldOffset = (32 +(i * 32));
        }
        exists = true;
        //This sets the version number to 2
        drinkMachine.versionNum = 2;
    }
    //This will close the file and return the boolean variable
    return exists;
}

/*
 * This function writes the contents of the drink machine out to the file and sets the structure size to 0. It does not
 * return any variable.
 */

void destroy(DrinkMachine &drinkMachine)
{
    //This is used to sort out in descending order the number of drinks sold
    bubbleSort(drinkMachine, drinkMachine.drinkItem);
    //This is used to display the sorted out drink machine
    dumpDrinkMachine(drinkMachine);
    //Sets the structure size to 0
    drinkMachine.drinkItem = 0;
    //closes the file
    drinkMachine.fileName.close();
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
    //The variable used in this function
    double price;
    //This will happen when the drink ID is valid
    if(drinkId >= 1)
    {
        //Initializing variables
        price = drinkMachine.drinks[drinkId - 1].price;
        change = amount - price;
        //This is what will happen when there is no change
        if (change < 0)
        {
            return false;
        }
        //This is what will happen when the drink is purchased
        else
        {
            drinkMachine.drinks[drinkId - 1].numOfDrinks--;
            drinkMachine.drinks[drinkId - 1].drinksPurchased++;
            drinkMachine.fileName.seekp(drinkMachine.drinks[drinkId - 1].quantityOffset, ios::beg);
            drinkMachine.fileName.write((char*)&(drinkMachine.drinks[drinkId - 1].numOfDrinks), 4);
            drinkMachine.fileName.seekp(drinkMachine.drinks[drinkId - 1].soldOffset, ios::beg);
            drinkMachine.fileName.write((char*)&(drinkMachine.drinks[drinkId - 1].drinksPurchased), 4);
            return true;
        }
    }
    //This will happen if the drink ID is not valid
    else
    {
        return false;
    }
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
