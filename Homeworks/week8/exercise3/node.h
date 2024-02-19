//
// Created by Leo Suzuki on 18.2.2024.
//

#pragma once

typedef char Stack_entry; // The program will use stacks with char entries.

class Node {
public:
    Stack_entry data;
    Node* next;

    Node(Stack_entry item, Node* link = nullptr) : data(item), next(link) {}
};