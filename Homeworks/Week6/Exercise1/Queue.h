//
// Created by Leo Suzuki on 4.2.2024.
//

#ifndef Exercise1_QUEUE_H
#define Exercise1_QUEUE_H
#include "Utility.h"

const int maxqueue = 10; //  small value for testing

class Queue {
public:
    Queue();
    bool empty() const;
    Error_code serve();
    Error_code append(const Queue_entry &item);
    Error_code retrieve(Queue_entry &item) const;

protected:
    int count;
    int front, rear;
    Queue_entry entry[maxqueue];
};


#endif // WEEK6_QUEUE_H
