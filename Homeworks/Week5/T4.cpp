#include <stack>
#include <iostream>
using namespace std;

int main()
/*
Pre:   The user supplies a sequence of integers in increasing order,
       terminated when an integer less than or equal to its predecessor is entered.
Post:  The integers are printed in decreasing order.
Uses:  The STL class stack and its methods
*/
{
    // Declare and initialize a stack of integers
    stack<int> numbers;

    // Request user input
    cout << "Enter a sequence of integers in increasing order like 2 3 6..., terminated by a decreasing or equal value like ....4 6 2: " << endl;

    // Read the first number
    int currentNumber, previousNumber;
    cin >> currentNumber;

    // Push the first number onto the stack
    numbers.push(currentNumber);

    // Keep track of the previous number
    previousNumber = currentNumber;

    // Continue reading and pushing numbers onto the stack as long as the input is in increasing order
    while (cin >> currentNumber && currentNumber > previousNumber)
    {
        // Push the number onto the stack
        numbers.push(currentNumber);

        // Update the previous number
        previousNumber = currentNumber;
    }

    // Print the integers in decreasing order
    cout << endl
         << "Integers in decreasing order: ";

    // Pop and print each integer in decreasing order
    while (!numbers.empty())
    {
        cout << numbers.top() << " ";
        numbers.pop();
    }

    cout << endl;

    return 0;
}