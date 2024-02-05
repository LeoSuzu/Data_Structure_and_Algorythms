#include <iostream>
using namespace std;

typedef char Entry;

#include "queue.h"
#include "stack.h"

// QUeue and Stack are defined in queue.h and stack.h

Error_code stack_to_queue(Stack &s, Queue &q)
/* 
 
Pre:   The Stack s and the Queue q have the same entry
      type.
Post: All entries from s have been moved to q.
      If there is not enough room in q to hold
      all entries in s return a code of overflow, otherwise
      return success.
 
*/

{
   Error_code outcome = success;
   Entry item;
   while (outcome == success && !s.empty()) {
      s.top(item);
      outcome = q.append(item);
      if (outcome == success) s.pop();
   }
   return (outcome);
}

Error_code queue_to_stack(Stack &s, Queue &q)
/* 
 
Pre:   The Stack s and the Queue q have the same entry
      type.
Post: All entries from q have been moved to s.
      If there is not enough room in s to hold
      all entries in q return a code of overflow, otherwise
      return success.
 
*/

{
   Error_code outcome = success;
   Entry item;
   while (outcome == success && !q.empty()) {
      q.retrieve(item);
      outcome = s.push(item);
      if (outcome == success) q.serve();
   }
   return (outcome);
}
 
Error_code move_stack(Stack &s, Stack &t)
/* 
 
Pre:   None.
Post: All entries from s have been moved in order
      onto the top of t.
      If there is not enough room in t to hold
      these entries return a code of overflow, otherwise
      return success.
 
*/

{
   Error_code outcome = success;
   Entry item;
   Stack temp;

   while (outcome == success && !s.empty()) {
      s.top(item);
      outcome = temp.push(item);
      if (outcome == success) s.pop();
   }

   while (outcome == success && !temp.empty()) {
      temp.top(item);
      outcome = t.push(item);
      if (outcome == success) temp.pop();
   }

   while (!temp.empty()) { //  replace any entries to s that can not fit on t 
      temp.top(item);
      s.push(item);
   }
   return (outcome);
}
 
Error_code reverse_move_stack(Stack &s, Stack &t)
/* 
 
Pre:   None.
Post: All entries from s have been moved in reverse order
      onto the top of t.
      If there is not enough room in t to hold
      these entries return a code of overflow, otherwise
      return success.
 
*/

{
   Error_code outcome = success;
   Entry item;
   while (outcome == success && !s.empty()) {
      s.top(item);
      outcome = t.push(item);
      if (outcome == success) s.pop();
   }
   return (outcome);
}
 
Error_code reverse_queue(Queue &q)
/* 
 
Pre:   None.
Post: All entries from q have been reversed.
 
*/

{
   Error_code outcome = success;
   Entry item;
   Stack temp;

   while (outcome == success && !q.empty()) {
      q.retrieve(item);
      outcome = temp.push(item);
      if (outcome == success) q.serve();
   }

   while (!temp.empty()) {
      temp.top(item);
      q.append(item);
      temp.pop();
   }
   return (outcome);
}
 
Error_code reverse_stack(Stack &s)
/* 
 
Pre:   None.
Post: All entries from s have been reversed.
 
*/

{
   Error_code outcome = success;
   Entry item;
   Queue temp;

   while (outcome == success && !s.empty()) {
      s.top(item);
      outcome = temp.append(item);
      if (outcome == success) s.pop();
   }

   while (!temp.empty()) {
      temp.retrieve(item);
      s.push(item);
      temp.serve();
   }
   return (outcome);
}

int main()
{

	Stack s;
	Queue q;

	s.push('a');
	s.push('b');
	s.push('c');

	s.print("Stack s before stack_to_queue(s, q):");
	q.print("Queue q before stack_to_queue(s, q):");

	stack_to_queue(s, q);

	s.print("Stack s after stack_to_queue(s, q):");
	q.print("Queue q after stack_to_queue(s, q):");

	s.print("Stack s before queue_to_stack(s, q):");
	q.print("Queue q before queue_to_stack(s, q):");

	queue_to_stack(s, q);

	if ( false )
		cout << "Heippa" << endl;

	s.print("Stack s after queue_to_stack(s, q):");
	q.print("Queue q after queue_to_stack(s, q):");

	Stack t;
	
	s.print("Stack s before move_stack(s, t):");
	t.print("Stack t before move_stack(s, t)::");

	move_stack(s, t);

	s.print("Stack s after move_stack(s, t):");
	t.print("Stack t after move_stack(s, t)::");

	t.print("Stack t before reverse_move_stack(t, s):");
	s.print("Stack s before reverse_move_stack(t, s):");

	reverse_move_stack(t, s);

	t.print("Stack t after reverse_move_stack(t, s):");
	s.print("Stack s after reverse_move_stack(t, s):");

	s.print("Stack s before reverse_stack(s):");
	
	reverse_stack(s);

	s.print("Stack s before reverse_stack(s):");

	return 0;
}
