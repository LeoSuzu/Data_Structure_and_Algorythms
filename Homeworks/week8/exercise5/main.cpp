//
// Created by Leo Suzuki on 18.2.2024.
//

#include <iostream>
#include "node.h"

int main() {
    Node_chain stack;

    // Testing push
    for (char ch = 'A'; ch <= 'E'; ch++) {
        stack.push(ch);
    }

    // Testing print
    stack.print("Original Stack");

    // Testing top and pop
    Stack_entry top_item;
    while (!stack.empty()) {
        stack.top(top_item);
        std::cout << "Top item: " << top_item << std::endl;
        stack.pop();
        stack.print("Stack after pop");
    }

    // Testing underflow
    if (stack.pop() == underflow) {
        std::cout << "Underflow occurred. Stack is empty." << std::endl;
    }

    // Testing copy_stack_c
    Node_chain original_stack;
    for (char ch = 'X'; ch <= 'Z'; ch++) {
        original_stack.push(ch);
    }

    Node_chain copied_stack;
    copy_stack_c(copied_stack, original_stack);

    original_stack.print("Original Stack");
    copied_stack.print("Copied Stack");

    // Testing size
    std::cout << "Size of Original Stack: " << original_stack.size() << std::endl;
    std::cout << "Size of Copied Stack: " << copied_stack.size() << std::endl;

    return 0;
}