//
// Created by Leo Suzuki on 18.2.2024.
//
# pragma once

#include "utility.h"

typedef char Stack_entry;  // The program will use stacks with char entries.

class Node {
public:
    Stack_entry data;
    Node *next;

    Node(Stack_entry item, Node *link = nullptr) : data(item), next(link) {}
};

class Node_chain {
public:
    Node_chain();
    ~Node_chain();  // Add a destructor to free memory.
    bool empty() const;
    Error_code pop();
    Error_code top(Stack_entry &item) const;
    Error_code push(const Stack_entry &item);
    void print(const char *title_p);
    int size() const;

    friend Error_code copy_stack_c(Node_chain &dest, const Node_chain &source);

private:
private:
    Node *top_node;  // Keep track of the top node.
    int stack_size;  // Counter for the size of the stack.
};
