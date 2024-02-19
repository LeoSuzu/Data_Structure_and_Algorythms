#include <iostream>
#include "node.h"

#include <iostream>
#include "node.h"

#include <iostream>
#include "node.h"

int main() {
    // Task a)

    // Creating nodes
    Node* p0a = new Node('0');
    Node* p1a = new Node('1', p0a);

    // Printing contents and addresses of each node
    Node* currentA = p0a;
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
    delete p0a;
    delete p1a;

    // Task b)
    // Creating nodes
    Node* p0b = new Node('0');
    Node* p1b = new Node('1', p0b);
    Node* p2b = new Node('1', p0b);

    // Printing contents and addresses of each node
    Node* currentB = p1b;
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

    // Creating nodes
    Node* p0c = new Node('0');
    Node* p1c = p0c->next = new Node('1');
    Node* p2c = p1c->next = new Node('2', p1c);

    // Printing contents and addresses of each node for one round
    Node* currentC = p0c;
    while (currentC != nullptr) {
        std::cout << "Task c) - Data: " << currentC->data
                  << ", Next: ";

        if (currentC->next != nullptr) {
            std::cout << currentC->next->data;
        } else {
            std::cout << "nullptr";
        }
        std::cout << ", Address: " << currentC << std::endl;

        if (currentC == p2c) {
            // Print additional information for p2c
            break; // Stop after one round, including p2c
        }

        currentC = currentC->next;
    }

    // Remember to free memory allocated for nodes
    delete p0c;
    delete p1c;
    delete p2c;

    return 0;
}