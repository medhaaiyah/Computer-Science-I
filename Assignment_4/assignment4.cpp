/*
 * Assignment 4 for CS 1337.013
 * Programmer: Medha Aiyah
 * Description: The assignment4.cpp file creates a phone book. It also calls the functions created in the
 *              UserListCommands.cpp for each of the certain features to be implemented and work for the user
 *              when they are using the UserId management.
 */

#include "memoryLeak.h"

#include <iostream>
#include <string>

#include "userList.h"
#include "menuList.h"
#include "userListCommands.h"

using namespace std;

int main()
{
    // create the phone book
    userList users;

    // create the commands

    printCommand print(users, std::cin, std::cout);
    insertCommand insert(users, std::cin, std::cout);
    findCommand find(users, std::cin, std::cout);
    updateCommand update(users, std::cin, std::cout);
    eraseCommand erase(users, std::cin, std::cout);
    printReverse reverse(users, std::cin, std::cout);

    // build the menuList and menuItems

    menuList menu("Userid management:");
    menuItem findItem('f', "find", find);
    menuItem insertItem('i', "insert", insert);
    menuItem updateItem('u', "update", update);
    menuItem eraseItem('e', "erase", erase);
    menuItem printItem('p',"print", print);
    menuItem printReverse('r', "print in reverse order", reverse);

    // add the menuItem values to the menulist

    menu.add(findItem);
    menu.add(insertItem);
    menu.add(updateItem);
    menu.add(eraseItem);
    menu.add(printItem);
    menu.add(printReverse);

    std::cout << "Starting the Userid management application\n\n";

    // run the menu
    menu.start();

    return 0;
}