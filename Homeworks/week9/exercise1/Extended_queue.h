//
// Created by Leo Suzuki on 19.2.2024.
//

#ifndef EXERCISE1_EXTENDED_QUEUE_H
#define EXERCISE1_EXTENDED_QUEUE_H
#include "Queue.h"


class Extended_queue : public Queue {
public:
    Extended_queue();
    ~Extended_queue();
    int size() const; //  returns the number of entries in the queue
    bool full() const;
    void clear();
    Error_code serve_and_retrieve(Queue_entry &item);
    Error_code append(const Queue_entry &item);
    Error_code serve();

private:
    int count; //  number of entries in the queue
};

#endif //EXERCISE1_EXTENDED_QUEUE_H
