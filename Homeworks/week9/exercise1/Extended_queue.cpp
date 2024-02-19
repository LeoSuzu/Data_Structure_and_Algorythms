//
// Created by Leo Suzuki on 19.2.2024.
//

#include "Extended_queue.h"

Extended_queue::Extended_queue() : Queue(), count(0) {}

Extended_queue::~Extended_queue() {
    clear();  // Clear the queue
}

int Extended_queue::size() const {
    return count;
}

Error_code Extended_queue::append(const Queue_entry &item) {
    Error_code outcome = Queue::append(item);  // Call the base class append
    if (outcome == success) {
        count++;  // Increment count on successful append
    }
    return outcome;
}

Error_code Extended_queue::serve() {
    Error_code outcome = Queue::serve();  // Call the base class serve
    if (outcome == success && count > 0) {
        count--;  // Decrement count on successful serve, ensure not to go below 0
    }
    return outcome;
}

bool Extended_queue::full() const {
    return false;
}

void Extended_queue::clear() {
    while (!empty()) {
        serve();
    }
    count = 0;  // Reset the count after clearing the queue
}

Error_code Extended_queue::serve_and_retrieve(Queue_entry &item) {
    if (empty()) {
        return underflow;
    }

    retrieve(item);
    serve();
    return success;
}