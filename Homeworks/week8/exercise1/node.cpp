//
// Created by Leo Suzuki on 18.2.2024.
//

#include "node.h"

Node_chain::Node_chain() : top_node(nullptr) {}

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
    return outcome;
}

void Node_chain::print(const char *title_p) {
    // Implementation for print remains the same as before.
}

// You can also implement the copy_stack_c function similarly to copy_stack in the array-based version.
Error_code copy_stack_c(Node_chain &dest, const Node_chain &source) {
    dest.~Node_chain();  // Destroy the current content of dest.
    dest = Node_chain();  // Reconstruct dest.
    Node *temp_top = source.top_node;
    while (temp_top != nullptr) {
        dest.push(temp_top->data);
        temp_top = temp_top->next;
    }
    return success;
}