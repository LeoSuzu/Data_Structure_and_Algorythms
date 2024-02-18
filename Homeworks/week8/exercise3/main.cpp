#include <iostream>
#include "node.h"

int main() {
    // Task a)

    // Creating nodes
    Node<char>* N0a = new Node<char>('0');
    Node<char>* N1a = new Node<char>('1');

    // Creating pointers
    Node<char>* p0a = N0a;
    Node<char>* p1a = N1a;

    // Linking nodes
    N0a->next = N1a;
    N1a->next = nullptr;

    // Printing contents and addresses of each node
    Node<char>* currentA = p0a;
    while (currentA != nullptr) {
        std::cout << "Task a) - Data: " << currentA->data
                  << ", Next: ";

        if (currentA->next != nullptr) {
            std::cout << currentA->next->data;
        } else {
            std::cout << "nullptr";
        }

        std::cout << ", Address: " << currentA << std::endl;

        currentA = currentA->next;
    }

    // Remember to free memory allocated for nodes
    delete N0a;
    delete N1a;


    // Task b)
    // Creating nodes
    Node<char>* N0b = new Node<char>('0');
    Node<char>* N1b = new Node<char>('1', N0b);

    // Creating pointers
    Node<char>* p0b = N0b;
    Node<char>* p1b = N1b;
    Node<char>* p2b = N1b;

    // Printing contents and addresses of each node
    Node<char>* currentB = p1b;
    while (currentB != nullptr) {
        std::cout << "Task b) - Data: " << currentB->data
                  << ", Next: ";

        if (currentB->next != nullptr) {
            std::cout << currentB->next->data;
        } else {
            std::cout << "nullptr";
        }

        std::cout << ", Address: " << currentB << std::endl;

        currentB = currentB->next;
    }

    // Remember to free memory allocated for nodes
    delete N0b;
    delete N1b;

    // Task c)

    // Creating nodes
    Node<char>* N0c = new Node<char>('0');
    Node<char>* N1c = new Node<char>('1');
    Node<char>* N2c = new Node<char>('2');

    // Creating pointers
    Node<char>* p0c = N0c;
    Node<char>* p1c = N1c;
    Node<char>* p2c = N2c;

    // Linking nodes
    N0c->next = N1c;
    N1c->next = N2c;
    N2c->next = N1c;

    // Printing contents and addresses of each node for one round
    Node<char>* currentC = p1c;
    while (currentC != nullptr) {
        std::cout << "Task c) - Data: " << currentC->data
                  << ", Next: ";

        if (currentC->next != nullptr) {
            std::cout << currentC->next->data;
        } else {
            std::cout << "nullptr";
        }

        std::cout << ", Address: " << currentC << std::endl;

        currentC = currentC->next;

        if (currentC == p1c) {
            break; // Stop after one round
        }
    }

    // Remember to free memory allocated for nodes
    delete N0c;
    delete N1c;
    delete N2c;

    return 0;
}