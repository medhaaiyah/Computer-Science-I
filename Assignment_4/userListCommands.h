/*
 * Assignment 4 for CS 1337.013
 * Programmer: Medha Aiyah
 * Description: The userListCommands.h file creates that classes that will be called in the assignment 4 cpp in order for
 *              certain features to work.
 */

#ifndef USERLISTCOMMANDS_H_
#define USERLISTCOMMANDS_H_

#include "memoryLeak.h"

#include <string>

#include "command.h"
#include "userList.h"

class userListCommand: public command
{
protected:
    userList &userIds;
    std::istream &in;
    std::ostream &out;

    userListCommand(userList &ids, std::istream &in, std::ostream &out)
            : userIds(ids), in(in), out(out)
    {
    }

    void display(const std::string &message)
    {
        out << message << "\n";
    }

    std::string read(const std::string &prompt)
    {
        std::string result;
        out << prompt << "\n";
        getline(in, result);
        return result;
    }
};

//This is the insertCommand class and it consists of a constructer, destructor, and an execute function

class insertCommand : public userListCommand
{
public:
    insertCommand(userList &ids, std::istream &in, std::ostream &out);
    ~insertCommand();
    void execute() override;
};

//This is the printCommand class and it consists of a constructer, destructor, and an execute function

class printCommand : public userListCommand
{
public:
    printCommand(userList &ids, std::istream &in, std::ostream &out);
    ~printCommand();
    void execute() override;
};


//This is the findCommand class and it consists of a constructer, destructor, and an execute function

class findCommand : public userListCommand
{
public:
    findCommand(userList &ids, std::istream &in, std::ostream &out);
    ~findCommand();
    void execute() override;
};

//This is the updateCommand class and it consists of a constructer, destructor, and an execute function

class updateCommand : public userListCommand
{
public:
    updateCommand(userList &ids, std::istream &in, std::ostream &out);
    ~updateCommand();
    void execute() override;
};

//This is the eraseCommand class and it consists of a constructer, destructor, and an execute function

class eraseCommand : public userListCommand
{
public:
    eraseCommand(userList &ids, std::istream &in, std::ostream &out);
    ~eraseCommand();
    void execute() override;
};

//This is the printReverse class and it consists of a constructer, destructor, and an execute function

class printReverse : public userListCommand
{
public:
    printReverse(userList &ids, std::istream &in, std::ostream &out);
    ~printReverse();
    void execute() override;
};

#endif /* USERLISTCOMMANDS_H_ */
