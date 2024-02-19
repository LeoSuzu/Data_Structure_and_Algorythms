//
// Created by Leo Suzuki on 19.2.2024.
//

#include "Queue.h"

// Constructor
Queue::Queue()
/*
Post: The Queue is initialized to be empty.
*/
{
    front = rear = NULL;
}

// Destructor
Queue::~Queue() {
    while (!empty()) {
        serve();
    }
}

// Append method
Error_code Queue::append(const Queue_entry &item)
/*
Post: Add item to the rear of the Queue and return a code of success
      or return a code of overflow if dynamic memory is exhausted.
*/
{
    Node *new_rear = new Node(item);
    if (new_rear == NULL) return overflow;
    if (rear == NULL) front = rear = new_rear;
    else {
        rear->next = new_rear;
        rear = new_rear;
    }
    return success;
}

// Serve method
Error_code Queue::serve()
/*
Post: The front of the Queue is removed.  If the Queue
      is empty, return an Error_code of underflow.
*/
{
    if (front == NULL) return underflow;
    Node *old_front = front;
    front = old_front->next;
    if (front == NULL) rear = NULL;
    delete old_front;
    return success;

}

// Empty method
bool Queue::empty() const  {
    return front == NULL;
}

// Size method
int Queue::size() const {
    int count = 0;
    Node *current = front;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}


// Retrieve method
Error_code Queue::retrieve(Queue_entry &item) const {
    if (front == NULL) return underflow;
    item = front->entry;
    return success;
}

//
Queue::Queue(const Queue &original) {
    front = rear = NULL;  // Initialize the new queue

    Node *original_current = original.front;

    while (original_current != NULL) {
        append(original_current->entry);  // Append each element to the new queue
        original_current = original_current->next;
    }
}

// overloaded assignment operator
void Queue::operator=(const Queue &original) {
    if (this != &original) {  // Avoid self-assignment
        // Clear the existing elements in the current queue
        while (!empty()) {
            serve();
        }

        Node *original_current = original.front;

        while (original_current != NULL) {
            append(original_current->entry);  // Append each element to the current queue
            original_current = original_current->next;
        }
    }
}
