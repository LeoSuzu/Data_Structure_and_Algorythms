#include <stack>
#include <iostream>
#include <string>
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

   cout << "Type in a line of text. Spaces are counted as characters." << endl;
   getline(cin, inputLine); // Read a line of text

   // Push each character onto the stack
   for (char ch : inputLine)
   {
      // Push to stack letter by letter
      characters.push(ch);
   }

   cout << endl
        << "Text in reverse order: ";
   // Pop and print each character in reverse order
   // While stack is not empty
   while (!characters.empty())
   {
      // Print the top of the stack
      cout << characters.top();
      // Pop the top of the stack
      characters.pop();
   }

   cout << endl;

   return 0;
}
