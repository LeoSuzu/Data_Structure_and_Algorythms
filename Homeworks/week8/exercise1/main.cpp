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

    return 0;
}
