/*
 * Assignment 4 for CS 1337.013
 * Programmer: Medha Aiyah
 * Description: The stack.h file contains the friend class definition and the node class declarations. You will need to
 *              implement all of the above constructors, destructor, and member functions.
 */

#ifndef STACK_H_
#define STACK_H_

#include <cstddef>
#include <cassert>
#include <iostream>

template <class Type>
class stack;

template <class Type>
class node
{
    friend class stack<Type>;
private:
    Type 		data;
    node<Type>* next;
public:
    node(const Type &newData, node<Type> *newNext = nullptr)
            : data(newData), next(newNext)
    {
    }
};

//This is the stack class and these are the private variable and the public member functions

template <class Type>
class stack
{
private:
    int count;
    node<Type>* firstNode;
public:
    stack();
    stack(const stack &other);
    const stack& operator=(const stack &rhs);
    virtual ~stack();
    const Type& top() const;
    Type& top();
    bool empty() const;
    std::size_t size() const;
    void push(const Type &value);
    void pop();
    void debug() const;
    void debug(std::ostream &out) const;
};


template <class Type>
void stack<Type>::debug() const
{
    debug(std::cout);
}

template <class Type>
void stack<Type>::debug(std::ostream &out) const
{
    out << "Number of items in stack: " << count << std::endl;
    out << "Top of stack is node @" << firstNode << std::endl;

    node<Type> *next = firstNode;

    while (next != nullptr)
    {
        out << "@" << next << ", next @" << next->next << ", data = " << next->data << std::endl;
        next = next->next;
    }
}

//This function is used to initialize the count variable and set the firstNode to nullptr

template <class Type>
stack <Type> ::stack() {
    count = 0;
    firstNode = nullptr;
}

//The copy constructor is used to frame the way that we are transferring the data over to the other stack
//There are two node pointers temp 1 and temp 2 that will monitor that the right data is being transferred over
//It will keep on doing this until it is empty

template <class Type>
stack <Type> ::stack(const stack &other) {
    firstNode = nullptr;
    count = 0;
    if(other.empty() == false)
    {
        firstNode = new node<Type>(&other->data, nullptr);
        node<Type>* temp1 = other.firstNode->next;
        node<Type>* temp2 = firstNode;
        while(temp1 !=nullptr)
        {
            temp2->next = new node<Type>(temp1->data, nullptr);
            temp2 = temp2->next;
            temp1 = temp1->next;
        }
        count = other->count;
    }
}

//This assignment operator is used to remove any nodes of the stack being copied
//It will also create copies of all of the nodes in the rhs stack and add them ot the this stack, preserving the
//order


template <class Type>
const stack<Type>& stack<Type> ::operator=(const stack <Type> &rhs) {
     node<Type>* nextNode = nullptr;
     if(this != &rhs)
     {
         while(firstNode != nullptr)
         {
             nextNode = firstNode->next;
             delete firstNode;
             firstNode = nextNode;
         }
         firstNode = new node<Type>(&rhs->data, nullptr);
         node<Type>* temp1 = rhs.firstNode->next;
         node<Type>* temp2 = firstNode;
         while(temp1 != nullptr)
         {
             temp2->next = new node<Type>(temp1->data, nullptr);
             temp2 = temp2->next;
             temp1 = temp1->next;
         }
         return *this;
     }
     else
     {
         return &rhs;
     }
 }

 //The destructor is used to delete all of the nodes in the stack so that the program does not have
 //any memory leaks.

template <class Type>
stack<Type>::~stack() {
    node<Type>* nextNode = nullptr;
    while(firstNode != nullptr)
    {
        nextNode = firstNode->next;
        delete firstNode;
        firstNode = nextNode;
    }
}

//This function is used to return the top element in the stack

template <class Type>
const Type& stack<Type>:: top() const{
   return firstNode->data;
}

//This function is used to return the top element in the stack

template <class Type>
Type& stack<Type>::top()
{
    return firstNode->data;
}

//This function will return true if the stack is empty and false if the stack has at least one entry

template <class Type>
bool stack<Type>::empty() const{
    if(!firstNode)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//This function is used to return the number of entries in the stack

template <class Type>
std::size_t stack<Type>::size() const
{
    return count;
}

//This function creates a new node that contains value and adds it to the top of the stack

template <class Type>
void stack<Type>::push(const Type &value){
    node<Type>* newNode = new node<Type>(value, nullptr);
    if(empty())
    {
        firstNode = newNode;
        newNode->next = nullptr;
        count++;
    }
    else
    {
        newNode->next = firstNode;
        firstNode = newNode;
        count++;
    }
}

//This function is used to remove the top entry from the stack when the stack is not empty.

template<class Type>
void stack<Type>::pop()
{
    node<Type>* temp = nullptr;
    if(!empty())
    {
        temp = firstNode->next;
        delete firstNode;
        firstNode = temp;
        count--;
    }
}
#endif /* STACK_H_ */
