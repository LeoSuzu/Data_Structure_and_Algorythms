//
// Created by Leo Suzuki on 18.2.2024.
//

#include "node.h"

Node_chain::Node_chain() : top_node(nullptr), stack_size(0) {}

Node_chain::~Node_chain() {
    while (!empty()) {
        pop();
    }
}

bool Node_chain::empty() const {
    return top_node == nullptr;
}

Error_code Node_chain::pop() {
    Error_code outcome = success;
    if (empty()) {
        outcome = underflow;
    } else {
        Node *old_top = top_node;
        top_node = top_node->next;
        delete old_top;
    }
    stack_size--;
    return outcome;
}

Error_code Node_chain::top(Stack_entry &item) const {
    Error_code outcome = success;
    if (empty()) {
        outcome = underflow;
    } else {
        item = top_node->data;
    }
    return outcome;
}

Error_code Node_chain::push(const Stack_entry &item) {
    Error_code outcome = success;
    Node *new_node = new Node(item, top_node);
    top_node = new_node;
    stack_size++;
    return success;
}

void Node_chain::print(const char *title_p) {
    // Implementation for print remains the same as before.
}

// You can also implement the copy_stack_c function similarly to copy_stack in the array-based version.
Error_code copy_stack_c(Node_chain &dest, const Node_chain &source) {
    dest.~Node_chain();  // Destroy the current content of dest.
    dest = Node_chain();  // Reconstruct dest.

    int source_size = source.size();
    for (int i = 0; i < source_size; ++i) {
        Stack_entry item;
        source.top(item);
        dest.push(item);
    }

    return success;
}

int Node_chain::size() const {
    int count = 0;
    Node *current = top_node;

    while (current != nullptr) {
        count++;
        current = current->next;
    }

    return count;
}