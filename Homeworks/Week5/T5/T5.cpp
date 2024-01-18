#include <iostream>
#include "Extended_stack.h"

using namespace std;

int main()
{
    Extended_stack stack;

    // Test push
    for (int i = 1; i <= 5; ++i)
    {
        if (stack.push(i) == overflow)
        {
            cerr << "Error: Stack overflow" << endl;
            return 1; // Exit with an error code
        }
    }

    // Test top and size
    Stack_entry top_item;
    stack.top(top_item);
    cout << "Top item: " << top_item << endl;
    cout << "Current size: " << stack.size() << endl;

    // Test pop
    stack.pop();
    cout << "After pop, current size: " << stack.size() << endl;

    // Test clear
    stack.clear();
    cout << "After clear, current size: " << stack.size() << endl;

    // Test empty and full
    cout << "Is the stack empty? " << (stack.empty() ? "Yes" : "No") << endl;
    cout << "Is the stack full? " << (stack.full() ? "Yes" : "No") << endl;

    return 0;
}
