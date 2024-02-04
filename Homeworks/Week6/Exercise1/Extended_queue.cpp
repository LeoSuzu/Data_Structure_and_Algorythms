//
// Created by Leo Suzuki on 4.2.2024.
//

#include "Extended_queue.h"

bool Extended_queue::full() const {
    return count == maxqueue;  // Assuming maxqueue is the maximum allowed size
}

int Extended_queue::size() const
/*
Post:   Return the number of entries in the Extended_queue.
*/
{
    return count;
}

void Extended_queue::clear() {
    count = 0;
    front = 0;
    rear = -1;  // Reset front and rear indices to empty state
}

void Extended_queue::print() const
{
    for (int i = front; i <= rear; ++i)
    {
        cout << entry[i] << " ";
    }
    cout << endl;
}

Error_code Extended_queue::serve_and_retrieve(Queue_entry &item) {
    if (empty()) {
        return underflow;  // Queue is empty, cannot serve and retrieve
    }

    item = entry[front];  // Retrieve the front entry
    serve();              // Serve the front entry
    return success;
}
