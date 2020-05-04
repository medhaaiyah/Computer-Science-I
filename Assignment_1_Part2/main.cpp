/*
 * Assignment 1 Part 2 Main Function for CS 1337
 * Programmer: Medha Aiyah
 * Description: This main function is used to make the drink machine and allow the user to by a specific drink.
 *
 */
//These are the appropriate headers used for this function
#include "drinkmachine.h"
using namespace std;

int main()
{
    //These are the variables that I am using in this function
    //I initialized some of the variables that are being used
    DrinkMachine drinkMachine;
    bool worked;
    double totalSales;
    double paid;
    double change;
    bool endingProgram = false;
    worked = create(drinkMachine);
    totalSales = 0;

    //This is what will happen if the file was opened and it was able to retrieve the information
    if(worked)
    {
        //This is the function used to display the chart of drinks along with their costs, quantity, and sold
        dumpDrinkMachine(drinkMachine);
        //This is what will happen when the program does not end
        while (endingProgram == false)
        {
            //Asks the user to enter a certain number for the drink they want to get
            cout << "Please enter the number of the drink being purchased" << endl;
            cout << fixed << setprecision(2);
            cout << '\t' << "0 Stop processing drink orders" << endl;

            unsigned int typesOfDrinks;
            typesOfDrinks = size(drinkMachine);
            //Used to display the drinks and their costs
            for (unsigned int i = 1; i <= typesOfDrinks; i++)
            {
                //Alter the widths to make it more like the example
                DrinkItem menu = drink(drinkMachine, i);
                cout << '\t' << menu.id << setw(16) << menu.name << setw(4) << '$' << menu.price << endl;
            }
            unsigned int userNum;
            //Where the user can put in the number of the drinks they want
            cin >> userNum;
            //This is what will happen if the user types in 0
            if (userNum == 0)
            {
                endingProgram = true;
            }
                //This is what will happen if a user types in an invalid number
            else if ((userNum < 0) || (userNum > typesOfDrinks))
            {
                cout << "The drink you requested is not valid" << endl;
                endingProgram = false;
            }
                //This is what will happen if the user types in a number between 1-7
            else if(0 < userNum <= typesOfDrinks)
            {
                //This is what will happen if the drink is available
                if (available(drinkMachine, userNum))
                {
                    do
                    {
                        //The prompt that is used for the user to pay for the item
                        cout << "The " << name(drinkMachine, userNum) << " you are requesting costs $" << price(drinkMachine, userNum) << endl;
                        cout << "Enter the payment amount for the drink: " << endl;
                        cin >> paid;
                        endingProgram = false;
                    }while(!purchase(drinkMachine, userNum, paid, change));
                    //This is what will happen if the user types in a bigger price amount
                    if (paid > price(drinkMachine, userNum))
                    {
                        change = paid - price(drinkMachine, userNum);
                        cout << "Your change is $" << change << endl;
                        cout << "Thank you for your purchase" << endl;
                        endingProgram = false;
                    }
                    //This is what will happen if the user pays the exact price of the drink
                    if (paid == price(drinkMachine, userNum))
                    {
                        cout << "Thank you for your purchase" << endl;
                        endingProgram = false;
                    }
                }
                    //This is what will happen if the drink is not available
                else
                {
                    cout << "Sorry we are out of " << name(drinkMachine, userNum) << "." << endl;
                    endingProgram = false;
                }
                totalSales += price(drinkMachine, userNum);
            }
        }
        //It will print out the drink machine sales at the very end.
        cout << "The drink machine sales were $" << totalSales << endl;
        destroy(drinkMachine);
    }
        //This is what will happen if the file is unable to be read
    else
    {
        cout << "The drink machine could not be created" << endl;
    }
    return 0;
}