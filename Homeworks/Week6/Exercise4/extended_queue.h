#pragma once

#include "queue.h"

class Extended_queue: public Queue {
public:
	bool full() const;
	int size() const;
	void clear();
	Error_code serve_and_retrieve(Queue_entry &item);

	/*EMME TEE T�T� OSAKKEIDEN TULOSTAMISTA VARTEN void print();*/
};
