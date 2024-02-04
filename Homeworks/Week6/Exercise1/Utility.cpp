#include <iostream>
using namespace std;

char get_command()
{
    char command;
    cout << "Enter a command: ";
    cin >> command;
    // Consume newline character left in the buffer
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return tolower(command);  // Convert to lowercase for case-insensitivity
}

bool user_says_yes()
{
	int c;
	bool initial_response = true;

	do {  //  Loop until an appropriate input is received.
		if (initial_response)
			cout << " (y,n)? " << flush;

		else
			cout << "Respond with either y or n: " << flush;

		do { //  Ignore white space.
			c = cin.get();
		} while (c == '\n' || c == ' ' || c == '\t');
		initial_response = false;
	} while (c != 'y' && c != 'Y' && c != 'n' && c != 'N');
	return (c == 'y' || c == 'Y');
}
