/*
 * userList.cpp
 *
 *  Created on: Apr 7, 2019
 *      Author: dgv130030
 */

#include <iostream>
#include <iomanip>
#include <utility>
#include <string>
#include "stack.h"

#include "userList.h"

bool userList::find(std::string userid) const
{
    // return true if the user id exists and false otherwise
    return ids.find(userid) != ids.end();
}
bool userList::add(const userEntry &entry)
{
    bool result = false;
    if ( !find(entry.getName()) )
    {
        // item was not found
        // add it
        auto insertResult = ids.insert(std::make_pair(entry.getName(), entry.getPassword()));
        result = insertResult.second;
    }
    return result;
}

bool userList::erase(std::string userid)
{
    auto numErased = ids.erase(userid);

    return numErased != 0;
}

bool userList::update(const userEntry &entry)
{
    bool result = false;
    if ( find(entry.getName()) )
    {
        // item was found
        // update it
        ids[entry.getName()] = entry.getPassword();
        result = true;
    }

    return result;
}

void userList::print(std::ostream &out) const
{
    const int NAME_LEN = 20;
    const int PASSWORD_LEN = 25;

    out << std::setw(NAME_LEN) << "User id";
    out << std::setw(PASSWORD_LEN) << "Password" << std::endl;

    for (const auto &elem : ids)
    {
        out << std::setw(NAME_LEN) << elem.first;
        out << std::setw(PASSWORD_LEN) << elem.second << std::endl;
    }
}

//In this member function, I had to create a stack and add the entries from the user id list to the stack

void userList::printReverse(std::ostream &out) const
{
    //This is used to initialize the value for the name length and the password length

    const int NAME_LENGTH = 20;
    const int PASSWORD_LENGTH = 25;

    //When the key part is retrieved from the map the type of object. So we get the first value and the second value

    stack<std::pair<const std::string, std::string>> list;

    for(const auto &elem : ids)
    {;
        list.push(elem);
    }
    out << std:: endl;
    out << std::setw(NAME_LENGTH) << "User id";
    out << std::setw(PASSWORD_LENGTH) << "Password" << std::endl;

    //This is what occurs when the list is not empty

    while(!list.empty())
    {
        const std::pair<const std::string, std::string> &next = list.top();
        out << std::setw(NAME_LENGTH) << next.first;
        out << std::setw(PASSWORD_LENGTH) << next.second << std::endl;
        list.pop();
    }
}


