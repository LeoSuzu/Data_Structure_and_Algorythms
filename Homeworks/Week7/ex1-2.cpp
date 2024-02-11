// Exercise 1

// queue.cpp
// a. function empty() is a member function of both Queue and Stack classes. It is a const member function, which
// means it does not modify the object it is called on. It returns a boolean value, true if
// the queue or stack is empty, and false otherwise.
// It is a query function, which means it is used to query the state of the object.
bool Queue::empty() const
/*
Post: Return true if the Queue is empty, otherwise return false.
*/
{
    return count == 0;
}

// queue.cpp
// b. retrieve() is a member function of the Queue class. It is a const member function, which means it does not modify
// the object it is called on. It takes a reference to a Queue_entry as a parameter, and returns an Error_code.
// It retrieves the front of the Queue and stores it in the output parameter item.
// If the Queue is empty, it returns an Error_code of underflow.
Error_code Queue::retrieve(Queue_entry &item) const

/*
Post: The front of the Queue retrieved to the output
      parameter item. If the Queue is empty return an Error_code of underflow.
*/

{
    if (count <= 0) return underflow;
    item = entry[front];
    return success;
}

//Extended_queue.cpp
// a. full() is a member function of the Extended_queue class. It is a const member function, which means it does not modify
bool Extended_queue::full() const
{
    return maxqueue == this -> count;
}

// Extended_queue.cpp
// b. clear() is a member function of the Extended_queue class.
// It does not return anything, and it does not take any parameters.
void Extended_queue::clear()
{
    this -> count = 0;
    this -> front = 0;
    this -> rear = maxqueue - 1;
}

// Extended_queue.cpp
// c. serve_and_retrieve() is a member function of the Extended_queue class.
// It returns an Error_code, and takes a reference to a Queue_entry as a parameter.
// It serves the front of the queue and stores it in the output parameter item.
// If the queue is empty, it returns an Error_code of underflow.
Error_code Extended_queue::serve_and_retrieve(Queue_entry &item)
{
    if (count <= 0) return underflow;
    item = entry[front];
    count--;
    front = ((front + 1) == maxqueue) ? 0 : (front + 1);
    return success;
}