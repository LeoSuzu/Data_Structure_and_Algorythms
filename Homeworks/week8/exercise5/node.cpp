//
// Created by Leo Suzuki on 18.2.2024.
//

#include "node.h"

// Constructors and destructors
Node_chain::Node_chain() : top_node(nullptr), stack_size(0) {}

Node_chain::~Node_chain() {
    while (!empty()) {
        pop();
    }
    top_node = nullptr;  // Ensure consistency
    stack_size = 0;      // Ensure consistency
}

// Public member functions
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

// New copy_stack_c function
Error_code copy_stack_c(Node_chain &dest, const Node_chain &source) {
    dest.~Node_chain();  // Destroy the current content of dest.
    dest = Node_chain();  // Reconstruct dest.

    // Copy the source stack to a temporary stack
    Node_chain temp_stack;
    // Traverse the source stack and push each element to the temporary stack
    Node *current_source = source.top_node;

    // While the current source is not null, push the data to the temporary stack
    while (current_source != nullptr) {
        temp_stack.push(current_source->data);
        current_source = current_source->next;
    }

    // While the temporary stack is not empty, pop the data and push it to the destination stack
    while (!temp_stack.empty()) {
        Stack_entry item;
        temp_stack.top(item);
        dest.push(item);
        temp_stack.pop();
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