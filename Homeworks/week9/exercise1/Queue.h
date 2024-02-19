//
// Created by Leo Suzuki on 19.2.2024.
//

#ifndef EXERCISE1_QUEUE_H
#define EXERCISE1_QUEUE_H
#include "Node.h"
#include "Utility.h"

// Class declaration, linked queues:

typedef char Queue_entry;

class Queue {
public:
//  standard Queue methods
    Queue();
    bool empty() const;
    Error_code retrieve(Queue_entry &item) const;
    Error_code append(const Queue_entry &item);
    Error_code serve();
//  safety features for linked structures
    ~Queue();
    Queue(const Queue &original);
    void operator =(const Queue &original);
    int size() const;
protected:
    Node *front, *rear;
};


#endif //EXERCISE1_QUEUE_H
