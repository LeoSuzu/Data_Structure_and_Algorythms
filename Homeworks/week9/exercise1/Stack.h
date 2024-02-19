//
// Created by Leo Suzuki on 19.2.2024.
//

#ifndef EXERCISE1_STACK_H
#define EXERCISE1_STACK_H

#include "Utility.h"
#include "Node.h"

typedef char Stack_entry;

class Stack {
public:
//  Standard Stack methods
    Stack();
    bool empty() const;
    Error_code push(const Stack_entry &item);
    Error_code pop();
    Error_code top(Stack_entry &item) const;
//  Safety features for linked structures
    ~Stack();
    Stack(const Stack &original);
    void operator =(const Stack &original);
protected:
    Node *top_node;
};



#endif //EXERCISE1_STACK_H
