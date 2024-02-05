#include <iostream>
using namespace std;

typedef char Entry;

#include "queue.h"
#include "stack.h"

// QUeue and Stack are defined in queue.h and stack.h
// Error codes are defined in utility.h

// Queue ja Stack ohjelma. Tehtävä viikko 6.4

Error_code stack_to_queue(Stack &s, Queue &q)
/*
Ennakkoehto: Pino s ja jono q käyttävät samaa tietotyyppiä.

Jälkiehto: Kaikki alkiot pinosta s on siirretty jono q:hen.
 Jos jonossa q ei ole tarpeeksi tilaa kaikille pinon s alkioille,
 palautetaan virhekoodi overflow, muuten palautetaan success.
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
Ennakkoehto: Pino s ja jono q käyttävät samaa tietotyyppiä.

 Jälkiehto: Kaikki alkiot jonosta q on siirretty pinoon s.
 Jos pinossa s ei ole tarpeeksi tilaa kaikille jonon q alkioille,
palautetaan virhekoodi overflow, muuten palautetaan success.
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
Ennakkoehto: Ei ole.

 Jälkiehto: Kaikki alkiot pinosta s on siirretty
 järjestyksessä pinon t päälle.
 Jos pinossa t ei ole tarpeeksi tilaa kaikille pinon s alkioille,
 palautetaan virhekoodi overflow, muuten palautetaan success.
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
Ennakkoehto: Ei ole.

Jälkiehto: Kaikki alkiot pinosta s on siirretty käänteisessäjärjestyksessä
pinon t päälle. Jos pinossa t ei ole tarpeeksi tilaa kaikille pinon s alkioille,
 palautetaan virhekoodi overflow, muuten palautetaan success.
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
 
Ennakkoehto: Ei ole.

Jälkiehto: Kaikki alkiot jonosta q on käännetty ympäri.
 
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
 
Ennakkoehto: Ei ole.

 Jälkiehto: Kaikki alkiot pinosta s on käännetty ympäri.
 
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

    s.print("Pino s ennen stack_to_queue(s, q):");
    q.print("Jono q ennen stack_to_queue(s, q):");

    stack_to_queue(s, q);

    s.print("Pino s jälkeen stack_to_queue(s, q):");
    q.print("Jono q jälkeen stack_to_queue(s, q):");

    s.print("Pino s ennen queue_to_stack(s, q):");
    q.print("Jono q ennen queue_to_stack(s, q):");

	queue_to_stack(s, q);

	if ( false )
		cout << "Testi" << endl;

    s.print("Pino s jälkeen queue_to_stack(s, q):");
    q.print("Jono q jälkeen queue_to_stack(s, q):");

    Stack t;

    s.print("Pino s ennen move_stack(s, t):");
    t.print("Pino t ennen move_stack(s, t)::");

    move_stack(s, t);

    s.print("Pino s jälkeen move_stack(s, t):");
    t.print("Pino t jälkeen move_stack(s, t)::");

    t.print("Pino t ennen reverse_move_stack(t, s):");
    s.print("Pino s ennen reverse_move_stack(t, s):");

    reverse_move_stack(t, s);

    t.print("Pino t jälkeen reverse_move_stack(t, s):");
    s.print("Pino s jälkeen reverse_move_stack(t, s):");

    s.print("Pino s ennen reverse_stack(s):");

    reverse_stack(s);

    s.print("Pino s jälkeen reverse_stack(s):");

	return 0;
}
