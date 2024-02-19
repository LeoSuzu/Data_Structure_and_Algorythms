//
// Created by Leo Suzuki on 19.2.2024.
//

#include "Extended_queue.h"
int Extended_queue::size() const
/*
Post: Return the number of entries in the Extended_queue.
*/
{
    Node *window = front;
    int count = 0;
    while (window != NULL) {
        window = window->next;
        count++;
    }
    return count;
}