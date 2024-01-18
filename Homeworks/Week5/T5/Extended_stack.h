#ifndef EXTENDED_STACK_H
#define EXTENDED_STACK_H
#include "Utility.h" // Include the correct header file

#pragma once


typedef double Stack_entry;
const int maxstack = 10;

class Extended_stack
{
public:
    Extended_stack();
    Error_code pop();
    Error_code push(const Stack_entry &item);
    Error_code top(Stack_entry &item) const;
    bool empty() const;
    void clear();      // Reset the stack to be empty.
    bool full() const; // If the stack is full,
                       // return true; else return false.
    int size() const;  // Return the number of entries
                       // in the stack.

private:
    int count;
    Stack_entry entry[maxstack];
};

#endif