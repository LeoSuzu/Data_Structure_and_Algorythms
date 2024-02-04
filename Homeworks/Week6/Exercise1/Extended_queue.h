//
// Created by Leo Suzuki on 4.2.2024.
//

#ifndef Exercise1_EXTENDED_QUEUE_H
#define Exercise1_EXTENDED_QUEUE_H

#include "Queue.h"

class Extended_queue : public Queue {
public:
    bool full() const;
    int size() const;
    void clear();
    void print() const;
    Error_code serve_and_retrieve(Queue_entry &item);

};

#endif // WEEK6_EXTENDED_QUEUE_H
