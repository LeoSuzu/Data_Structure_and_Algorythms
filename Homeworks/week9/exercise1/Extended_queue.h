//
// Created by Leo Suzuki on 19.2.2024.
//

#ifndef EXERCISE1_EXTENDED_QUEUE_H
#define EXERCISE1_EXTENDED_QUEUE_H
#include "Queue.h"
#include "Utility.h"

class Extended_queue: public Queue {
public:
    bool full() const;
    int size() const;
    void clear();
    Error_code serve_and_retrieve(Queue_entry &item);
};


#endif //EXERCISE1_EXTENDED_QUEUE_H
