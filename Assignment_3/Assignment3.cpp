/*
 * Assignment 3 for CS 1337.013
 * Programmer: Medha Aiyah
 * Description: This main function implements the functions created in the PhoneBook and PhoneEntry classes.
 *              The user is able to add name's and number's to the PhoneBook. They are also able to remove a
 *              person by name, number, or by name and number. This main function is also used to test out the
 *              different constructors, and the use of the assignment operator.
 */
#include <iostream>
#include "PhoneEntry.h"
#include "PhoneBook.h"
using namespace std;

int main()
{
    //It creates a phone book that will be able to store up to 50 entries.

    PhoneBook book(50);

    //Adding the names and the numbers of the people in the phone book called book.

    book.add("Sarah Jane Smith", "555-555-1212");
    book.add("Medha Aiyah", "916-749-6705");
    book.add("Shivani Gandhi", "361-442-9842");
    book.add("Sanjeev Penupala", "469-666-4613");
    book.add("Afrida Frizzle", "123-456-7891");
    book.add("Beatrice Agron", "512-909-6138");

    cout << endl;

    //Using the phoneEntryAt function to display the contents that was added in the Phone Book called book

    cout << "Display Total Entries using phoneEntryAt: " << endl << endl;

    for (unsigned int index = 0; index < book.getSize(); index++)
    {
        //Create a reference to the returned PhoneEntry

        const PhoneEntry &item = book.phoneEntryAt(index);

        //Use the << operator to display the name and number

        cout << item << endl;
    }

    cout << endl;

    //Using the operator[] to display the total entries using subscripts

    cout << "Display Total Entries using subscripts: " << endl << endl;

    for(unsigned int index = 0; index < book.getSize(); index++)
    {
        //Create a reference to the returned PhoneEntry

        const PhoneEntry &item = book[index];

        //Use the << operator to display the name and number

        cout << item << endl;
    }

    cout << endl;

    //Testing to see if option 1 works if you remove by name

    cout << "Remove the entry by name 'Medha Aiyah': " << endl << endl;

    book.removeByName("Medha Aiyah");
    for (unsigned int index = 0; index < book.getSize(); index++)
    {
        //Create a reference to the returned PhoneEntry

        const PhoneEntry &item = book.phoneEntryAt(index);

        //Use the << operator to display the name and number

        cout << item << endl;
    }

    cout << endl;

    //Adding back the name and number that was removed by name

    book.add("Medha Aiyah", "916-749-6705");

    //Testing to see if option 1 works if you remove by number

    cout << "Remove the entry by number '123-456-7891': " << endl << endl;

    book.removeByNumber("123-456-7891");
    for (unsigned int index = 0; index < book.getSize(); index++)
    {
        //Create a reference to the returned PhoneEntry

        const PhoneEntry &item = book.phoneEntryAt(index);

        //Use the << operator to display the name and number

        cout << item << endl;
    }

    cout << endl;

    //Adding back the name and number that was removed by number

    book.add("Afrida Frizzle", "123-456-7891");

    //Testing to see if option 1 works if you remove name and number

    cout << "Remove the entry 'Beatrice Agron, 512-909-6138': " << endl << endl;

    book.remove(PhoneEntry("Beatrice Agron", "512-909-6138"));
    for (unsigned int index = 0; index < book.getSize(); index++)
    {
        //Create a reference to the returned PhoneEntry

        const PhoneEntry &item = book.phoneEntryAt(index);

        //Use the << operator to display the name and number

        cout << item << endl;
    }

    //Using the copy constructor to create a PhoneBook object (book 1)
    PhoneBook book1(book);

    //Adding a name to book 1

    book1.add("Vish Aiyah", "916-752-7548");

    cout << endl;

    //Displaying book1 and making sure that the name that we added is shown in PhoneBook

    cout << "Print after using the copy constructor (book 1): " << endl << endl;
    for (unsigned int index = 0; index < book1.getSize(); index++)
    {
        //Create a reference to the returned PhoneEntry

        const PhoneEntry &item = book1.phoneEntryAt(index);

        //Use the << operator to display the name and number

        cout << item << endl;
    }

    cout << endl;

    //Using the assignment operator

    book1 = book;

    //Displaying book and making sure that the name that we added in book1 does not show in the PhoneBook

    cout << "Now print book after doing book1 = book: " << endl << endl;
    for (unsigned int index = 0; index < book.getSize(); index++)
    {
        //Create a reference to the returned PhoneEntry

        const PhoneEntry &item = book.phoneEntryAt(index);

        //Use the << operator to display the name and number

        cout << item << endl;
    }

    cout << endl;

    //*************************************************************************************//

    //Creating a phone up that is an empty object (book2)

    PhoneBook book2;

    cout << "Declaring empty object: " << endl << endl;

    //Adding names and number to Phone Book 2

    book2.add("Chris Soremekun", "512-785-5224");
    book2.add("Rajni Aiyah", "916-705-4047");
    book2.add("Vamika Chatlani", "435-546-6578");
    book2.add("Olivia Castro", "972-974-6462");
    for (unsigned int index = 0; index < book2.getSize(); index++)
    {
        //Create a reference to the returned PhoneEntry

        const PhoneEntry &item = book2.phoneEntryAt(index);

        //Use the << operator to display the name and number

        cout << item << endl;
    }

    cout << endl;

    //Testing an assignment operator on an empty function

    cout << "Use the assignment operator (to display book3) - Olivia removed: " << endl << endl;

    //Creating an empty PhoneBook 3

    PhoneBook book3;
    book3 = book2;
    book3.removeByName("Olivia Castro");

    for (unsigned int index = 0; index < book3.getSize(); index++)
    {
        // Create a reference to the returned PhoneEntry

        const PhoneEntry &item = book3.phoneEntryAt(index);

        //Use the << operator to display the name and number

        cout << item << endl;
    }

    cout << endl;

    //Displaying the values of PhoneBook2 to make sure it varies from PhoneBook3

    cout << "Using the assignment operator (display book2) - Olivia should be there: " << endl << endl;

    for (unsigned int index = 0; index < book2.getSize(); index++)
    {
        //Create a reference to the returned PhoneEntry

        const PhoneEntry &item = book2.phoneEntryAt(index);

        //Use the << operator to display the name and number

        cout << item << endl;
    }

    return 0;
}