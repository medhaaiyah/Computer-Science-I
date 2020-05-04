/*
 * Assignment 4 for CS 1337.013
 * Programmer: Medha Aiyah
 * Description: The userListCommands.cpp file includes the constructor and destructor and the execute code that was called
 *              in the userListCommands.h file.
 */
#include "userListCommands.h"

#include <iostream>
#include <string>


insertCommand::insertCommand(userList &ids, std::istream &in, std::ostream &out)
        : userListCommand(ids, in, out)
{
}

insertCommand::~insertCommand()
{
}

void insertCommand::execute()
{
    std::string userName = read("Enter the user id to be added:");
    std::string password = read("Enter the password for user " + userName + ":");

    bool result = userIds.add(userName, password);

    if (result)
    {
        display("User " + userName+ " was successfully added");
    }
    else
    {
        display("User " + userName+ " could not be added and may already exist");
    }
}

printCommand::printCommand(userList &ids, std::istream &in, std::ostream &out)
        : userListCommand(ids, in, out)
{
}

printCommand::~printCommand()
{
}

void printCommand::execute()
{
    display("Current list of users and passwords\n");

    userIds.print(out);
}

//This is a findCommand Constructor

findCommand::findCommand(userList &ids, std::istream &in, std::ostream &out)
        : userListCommand(ids, in, out)
{
}

//This is a findCommand Destructor

findCommand::~findCommand()
{
}

//This function is used to display whether or not the user was found or not found

void findCommand::execute()
{
    std::string userName = read("Enter the user id to search for:");
    bool result = userIds.find(userName);
    if (result)
    {
        display("User " + userName+ " was found");
    }
    else
    {
        display("User " + userName+ " was not found");
    }

}

//This is a updateCommand Constructor

updateCommand::updateCommand(userList &ids, std::istream &in, std::ostream &out)
        : userListCommand(ids, in, out)
{
}

//This is a updateCommand Destructor

updateCommand::~updateCommand()
{
}

//This function will first read that the userName is valid. Then if it is valid it will ask it to enter the
//password it will want it to be updated to.

void updateCommand::execute()
{
    std::string userName = read("Enter the user id to be updated:");
    bool result = userIds.find(userName);
    if(result)
    {
        std::string password = read("Enter the new password for user " + userName);
        userIds.update(userName, password);
        display("The password for user " + userName+ " was successfully updated");
    }
    else
    {
        display("User " + userName+ " was not found");
    }

}

//This is a eraseCommand Constructor

eraseCommand::eraseCommand(userList &ids, std::istream &in, std::ostream &out)
        : userListCommand(ids, in, out)
{
}

//This is a eraseCommand Destructor

eraseCommand::~eraseCommand()
{
}

//This function will first read that the userName is valid. If it is it will use the erase function to erase the
//user.

void eraseCommand::execute()
{
    std::string userName = read("Enter the user id to be erased:");
    bool result = userIds.erase(userName);
    if (result)
    {
        display("The entry for user " + userName+ " was successfully erased");
    }
    else
    {
        display("User " + userName+ " was not found");
    }
}

//This is a printReverse Constructor

printReverse::printReverse(userList &ids, std::istream &in, std::ostream &out)
        : userListCommand(ids, in, out)
{
}

//This is a printReverse Destructor

printReverse::~printReverse()
{
}

//This function is used to display the user's information in reverse order.

void printReverse::execute()
{
    display("Current list of users and passwords in reverse order");
    userIds.printReverse(out);
}

