// T1b) Reversing a line of text in reverse order
#include <stack>
#include <iostream>
#include <string> // Include the string header for std::getline
using namespace std;

int main()
/*
Pre:   The user supplies a line of text.
Post:  The characters of the text are printed in reverse order.
Uses:  The STL class stack and its methods
*/
{
   string inputLine;
   stack<char> characters; // declares and initializes a stack of characters

   cout << "Type in a line of text." << endl;
   getline(cin, inputLine); // Read a line of text

   // Push each character onto the stack
   for (char ch : inputLine)
   {
      characters.push(ch); // Push to stack
   }

   cout << endl
        << "Text in reverse order: ";
   // Pop and print each character in reverse order
   while (!characters.empty())
   {
      cout << characters.top();
      characters.pop();
   }
   cout << endl;

   return 0;
}
