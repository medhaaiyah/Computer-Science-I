/*Assignment 3 for CS 1337.013
 *Programmer: Medha Aiyah
 *Description: This file is the header file for the PhoneBook class.
 */
#ifndef ASSIGNMENT_3_PHONEBOOK_H
#define ASSIGNMENT_3_PHONEBOOK_H


# include "PhoneEntry.h"

class PhoneBook
{
    private:
        unsigned int maximumSize;
        PhoneEntry *entries;
        unsigned int numEntries;
    public:
        PhoneBook();
        PhoneBook(unsigned int maxEntries);
        PhoneBook(const PhoneBook &otherBook);
        ~PhoneBook();
        void add(std::string name, std::string number);
        void removeByName(std::string name);
        void removeByNumber(std::string number);
        void remove(const PhoneEntry &entry);
        unsigned int getSize() const;
        unsigned int getMaxSize() const;
        const PhoneEntry& phoneEntryAt(unsigned int position) const;
        const PhoneEntry& operator[](unsigned int position) const;
        const PhoneBook& operator=(const PhoneBook &rhs);

};

#endif //ASSIGNMENT_3_PHONEBOOK_H
