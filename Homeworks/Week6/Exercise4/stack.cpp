#include "stack.h"


Error_code Stack::push(const Stack_entry &item)

{
	Error_code outcome = success;
	if (count >= maxstack)
		outcome = overflow;
	else
		entry[count++] = item;
	return outcome;
}


Error_code Stack::pop()

{
	Error_code outcome = success;
	if (count == 0)
		outcome = underflow;
	else --count;
	return outcome;
}


Error_code Stack::top(Stack_entry &item) const

{
	Error_code outcome = success;
	if (count == 0)
		outcome = underflow;
	else
		item = entry[count - 1];
	return outcome;
}


bool Stack::empty() const

{
	bool outcome = true;
	if (count > 0) outcome = false;
	return outcome;
}


Stack::Stack()
{
	count = 0;
}

void Stack::print(const char *title_p)
{
	bool first_time = true;

	std::cout << title_p << endl;
	for ( int i = 0; i < ( int )( strlen( title_p ) ); i++ )
		cout << "=";
	cout << endl << endl;

	if ( false == this->empty() ) {
		for ( int i = this->count - 1; i >= 0; i-- ) {
			cout << this->entry[ i ];

			if ( true == first_time && this->count > 0 )
				cout << " <--- top" << endl;
			else
				cout << endl;

			first_time = false;
		}

		cout << "--" << endl << endl << endl;
	}
	else
		cout << "Stack is empty." << endl << endl << endl;
}
