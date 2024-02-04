#include <iostream>
#include "Extended_queue.h"
#include "Queue.h"
#include "Utility.h"

// Section 3.4:

void help();
bool do_command(char c, Extended_queue &test_queue);

int main()
/*
Post: Accepts commands from user as a menu-driven demonstration program for
      the class Extended_queue.
Uses: The class Extended_queue and the functions introduction,
      get_command, and do_command.
*/

{
    Extended_queue test_queue;
    help();
    while (do_command(get_command(), test_queue));
}


void help()
/*
Post: A help screen for the program is printed, giving the meaning of each
      command that the user may enter.
*/

{
    cout << endl
         << "This program allows the user to enter one command" << endl
         << "(but only one) on each input line." << endl
         << "For example, if the command S is entered, then" << endl
         << "the program will serve the front of the queue." << endl
         << endl

         << " The valid commands are:" << endl
         << "A - Append the next input character to the extended queue" << endl
         << "S - Serve the front of the extended queue" << endl
         << "R - Retrieve and print the front entry." << endl
         << "# - The current size of the extended queue" << endl
         << "C - Clear the extended queue (same as delete)" << endl
         << "P - Print the extended queue" << endl
         << "H - This help screen" << endl
         << "Q - Quit" << endl

         << "Press <Enter> to continue." << flush;

    char c;
    do {
        cin.get(c);
    } while (c != '\n');
}


bool do_command(char c, Extended_queue &test_queue)
/*
Pre:  c represents a valid command.
Post: Performs the given command c on the Extended_queue test_queue.
      Returns false if c == 'q', otherwise returns true.
Uses: The class Extended_queue.
*/
{
    bool continue_input = true;
    Queue_entry x;

    switch (c) {
        case 'a':
            cout << "Enter a character to append: ";
            cin >> x;
            if (test_queue.append(x) == overflow)
                cout << "Queue is full. Cannot append." << endl;
            break;

        case 's':
            if (test_queue.serve() == underflow)
                cout << "Queue is empty. Cannot serve." << endl;
            break;

        case 'r':
            if (test_queue.retrieve(x) == underflow)
                cout << "Queue is empty." << endl;
            else
                cout << "The first entry is: " << x << endl;
            break;

        case '#':
            cout << "Current size of the extended queue: " << test_queue.size() << endl;
            break;

        case 'c':
            test_queue.clear();
            cout << "Extended queue cleared." << endl;
            break;

        case 'p':
            cout << "Extended queue contents: ";
            test_queue.print();
            break;

        case 'h':
            help();
            break;

        case 'q':
            cout << "Extended queue demonstration finished." << endl;
            continue_input = false;
            break;

        default:
            cout << "Invalid command. Please enter a valid command." << endl;
            break;
    }
    return continue_input;
}


