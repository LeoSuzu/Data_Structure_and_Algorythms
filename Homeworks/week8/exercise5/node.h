//
// Created by Leo Suzuki on 18.2.2024.
//
# pragma once

#include "utility.h"

// Define the Stack_entry type to be char for now.
typedef char Stack_entry;

class Node {
public:
    // Data members
    Stack_entry data;
    // Pointer to the next node
    Node *next;
    // Constructors
    Node(Stack_entry item, Node *link = nullptr) : data(item), next(link) {}
};

class Node_chain {
public:
    // Constructors and destructors
    Node_chain();
    ~Node_chain();
    // Public member functions
    bool empty() const;
    Error_code pop();
    Error_code top(Stack_entry &item) const;
    Error_code push(const Stack_entry &item);
    void print(const char *title_p);
    int size() const;

    // Friend functions
    friend Error_code copy_stack_c(Node_chain &dest, const Node_chain &source);

private:
    Node *top_node; // Pointer to the top of the stack
    int stack_size; //
};
