/*Assignment 3 for CS 1337.013
 *Programmer: Medha Aiyah
 *Description: This file is the header file for the PhoneEntry class.
 */
#ifndef ASSIGNMENT_3_PHONEENTRY_H
#define ASSIGNMENT_3_PHONEENTRY_H


class PhoneEntry
{
    private:
        std::string number;
        std::string name;
    public:
        PhoneEntry();
        PhoneEntry(const PhoneEntry &other);
        PhoneEntry(std::string newName, std::string newNumber);
        ~PhoneEntry();
        std::string getName() const;
        std::string getNumber() const;
        void setName(std::string newName);
        void setNumber(std::string newNumber);
        const PhoneEntry& operator=(const PhoneEntry &rhs);
        bool operator==(const PhoneEntry &rhs) const;
        bool operator!=(const PhoneEntry &rhs) const;

};

std::ostream& operator<<(std::ostream &out, const PhoneEntry &rhs);

#endif //ASSIGNMENT_3_PHONEENTRY_H
