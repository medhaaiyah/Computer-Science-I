/*
 * userList.h
 *
 *  Created on: Apr 7, 2019
 *      Author: dgv130030
 */

#ifndef USERLIST_H_
#define USERLIST_H_

#include "memoryLeak.h"
#include <iostream>
#include <string>
#include <map>

class userEntry
{
private:
    std::string userName;
    std::string userPassword;
public:
    userEntry() : userEntry("","") {}
    userEntry(std::string name, std::string password)
            : userName(name), userPassword(password) { }
    virtual ~userEntry() {}
    bool verify(std::string password);
    std::string getName() const { return userName;}
    std::string getPassword() const { return userPassword;}
    void setName(std::string newName) { userName = newName;}
    void setPassword(std::string newPassword) {userPassword = newPassword;}
};

class userList
{
private:
    std::map<std::string, std::string> ids;
    typedef std::map<std::string, std::string>::iterator iterator;
    typedef const iterator								 const_iterator;
public:
    userList() : ids() {};
    virtual ~userList() {}
    bool find(std::string userid) const;
    bool add(std::string userid, std::string password)
    {
        return add(userEntry(userid, password));
    }
    bool add(const userEntry &entry);
    bool erase(std::string userid);
    bool update(std::string userid, std::string password)
    {
        return update(userEntry(userid, password));
    }
    bool update(const userEntry &entry);
    iterator begin() noexcept {return ids.begin();}
//		const_iterator begin() const noexcept {return ids.begin();}
    iterator end() noexcept {return ids.end();}
//		const_iterator end() const noexcept {return ids.end();}
    void print(std::ostream &out) const;
    void print() const { print(std::cout);}
    void printReverse(std::ostream &out) const;
    void printReverse() const {printReverse(std::cout);}
};

#endif /* USERLIST_H_ */