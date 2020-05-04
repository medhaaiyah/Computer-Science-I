/*Assignment 3 for CS 1337.013
 *Programmer: Medha Aiyah
 *Description: This file is used to program the constructors, destructors, and the member functions for the PhoneEntry
 *             class.
 */
#include <iostream>
#include "PhoneEntry.h"
using namespace std;

//This PhoneEntry constructor should initialize the private variable

PhoneEntry::PhoneEntry()
{
    name = "";
    number = "";
}

//This is using the parameter and initialize the private variables as a this pointer

PhoneEntry::PhoneEntry(const PhoneEntry &other)
{
    this->name = other.name;
    this->number = other.number;
}

//This PhoneEntry constructor should initialize the private variables with the given parameters

PhoneEntry::PhoneEntry(string newName, string newNumber)
{
    name = newName;
    number = newNumber;
}

//This is destructor for the PhoneEntry class.

PhoneEntry::~PhoneEntry()
{
    //Not sure if we need this
    name = "";
    number = "";
}

//The getName member function returns the name

string PhoneEntry::getName() const
{
    return name;
}

//The getNumber member functions returns the number

string PhoneEntry::getNumber() const
{
    return number;
}

//The setName member function sets the private variable, name, to the parameter newName.

void PhoneEntry::setName(std::string newName)
{
    name = newName;
}

//The setNumber member function sets the private variable, number, to the parameter newNumber.

void PhoneEntry::setNumber(std::string newNumber)
{
    number = newNumber;
}
const PhoneEntry& PhoneEntry::operator=(const PhoneEntry &rhs)
{
    if(this != &rhs)
    {
        name = rhs.name;
        number = rhs.number;
    }

    return *this;
}

//The operator== should return true only if both phone entries contain the same values for name and number

bool PhoneEntry::operator==(const PhoneEntry &rhs) const
{
    bool validity;
    if(name == rhs.name && number == rhs.number)
    {
        validity = true;
    }
    else
    {
        validity = false;
    }
    return validity;
}

//The operator!= should return false only if both phone entries contain the same values for name and number

bool PhoneEntry::operator!=(const PhoneEntry &rhs) const
{
    bool validity;
    if(name == rhs.name && number == rhs.number)
    {
        validity = false;
    }
    else
    {
        validity = true;
    }
    return validity;
}

//The operator<< member function will output the contents of a phone entry to the output stream.
//Should contain both the name and number

std::ostream& operator<<(std::ostream &out, const PhoneEntry &rhs)
{
    out << rhs.getName() << " " << rhs.getNumber();
    return out;
}
