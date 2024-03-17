#include <iostream>
#include "List.h"

using namespace std;
void print_entry(List_entry &x) {
    cout << x << " ";
}


// Exercice 1, 2 and 3


// ####################################  Eercise 3
// Singly Linked Node
template<typename T>
struct SinglyNode {
    T data;
    SinglyNode<T>* next;

    // Constructor
    SinglyNode(const T& value) : data(value), next(nullptr) {}
};

// Doubly Linked Node
template<typename T>
struct DoublyNode {
    T data;
    DoublyNode<T>* prev;
    DoublyNode<T>* next;

    // Constructor
    DoublyNode(const T& value) : data(value), prev(nullptr), next(nullptr) {}
};

int main() {
    List list;
    List dest;
    List list2;
    List oddlist;
    List evenlist;
    Error_code result;
    List_entry removed;
    list.insert_first(6);
    list.insert_first(7);
    list.insert_first(8);
    list.insert_first(9);
    list.insert_first(100);

    // ####################################  Eercise 1

    // E1. Error_code insert_first(const List_entry &x, List &a_list)
    cout << "Test E1 - insert_first:" << endl;
    cout << "Original list: ";
    list.traverse(print_entry);
    cout << endl;

    result = list.insert_first(0);
    if (result == success) {
        cout << "Insertion successful!" << endl;
    } else {
        cout << "Error inserting first entry!" << endl;
    }
    cout << "Modified list: ";
    list.traverse(print_entry);
    cout << endl;

    // E2. Error_code remove_first(List_entry &x, List &a_list)
    cout << "Test E2 - remove_first:" << endl;
    cout << "Original list: ";
    list.traverse(print_entry);
    cout << endl;

    result = list.remove_first(removed);
    if (result == success) {
        cout << "Removal successful! Removed entry: " << removed << endl;
    } else {
        cout << "Error removing first entry!" << endl;
    }
    cout << "Modified list: ";
    list.traverse(print_entry);
    cout << endl;

    // E3. Error_code insert_last(const List_entry &x, List &a_list)
    cout << "Test E3 - insert_last:" << endl;
    cout << "Original list: ";
    list.traverse(print_entry);
    cout << endl;

    result = list.insert_last(6);
    if (result == success) {
        cout << "Insertion successful!" << endl;
    } else {
        cout << "Error inserting last entry!" << endl;
    }
    cout << "Modified list: ";
    list.traverse(print_entry);
    cout << endl;

    // E4. Error_code remove_last(List_entry &x, List &a_list)
    cout << "Test E4 - remove_last:" << endl;
    cout << "Original list: ";
    list.traverse(print_entry);
    cout << endl;

    result = list.remove_last(removed);
    if (result == success) {
        cout << "Removal successful! Removed entry: " << removed << endl;
    } else {
        cout << "Error removing last entry!" << endl;
    }
    cout << "Modified list: ";
    list.traverse(print_entry);
    cout << endl;

    // E5. Error_code median_list(List_entry &x, List &a_list)
    cout << "Test E5 - median_list:" << endl;
    cout << "Original list: ";
    list.traverse(print_entry);
    cout << endl;

    result = list.median_list(removed);
    if (result == success) {
        cout << "Median entry: " << removed << endl;
    } else {
        cout << "Error getting median entry!" << endl;
    }

    // E6. Error_code interchange(int pos1, int pos2, List &a_list)
    cout << "Test E6 - interchange:" << endl;
    cout << "Original list: ";
    list.traverse(print_entry);
    cout << endl;

    result = list.interchange(0, 4);
    if (result == success) {
        cout << "Interchange successful!" << endl;
    } else {
        cout << "Error interchanging entries!" << endl;
    }
    cout << "Modified list: ";
    list.traverse(print_entry);
    cout << endl;

    // E7. void reverse_traverse_list(List &a_list, void (*visit)(List_entry &))
    cout << "Test E7 - reverse_traverse_list:" << endl;
    cout << "Original list: ";
    list.traverse(print_entry);
    cout << endl;

    cout << "Reversed list: ";
    list.reverse_traverse_list(print_entry);
    cout << endl;

    // E8. Error_code copy(List &dest, List &source)
    cout << "Test E8 - copy:" << endl;
    cout << "Original source list: ";
    list.traverse(print_entry);
    cout << endl;
    cout << "Original destination list: ";
    dest.traverse(print_entry);
    cout << endl;

    result = list.copy(dest, list);
    if (result == success) {
        cout << "Copy successful!" << endl;
    } else {
        cout << "Error copying list!" << endl;
    }
    cout << "Modified destination list: ";
    dest.traverse(print_entry);
    cout << endl;

    // E9. Error_code join(List &list1, List &list2)
    list2.insert_first(6);
    list2.insert_first(7);
    list2.insert_first(8);
    cout << "Test E9 - join:" << endl;
    cout << "Original list1: ";
    list.traverse(print_entry);
    cout << endl;
    cout << "Original list2: ";
    list2.traverse(print_entry);
    cout << endl;

    result = list.join(list, list2);
    if (result == success) {
        cout << "Join successful!" << endl;
    } else {
        cout << "Error joining lists!" << endl;
    }
    cout << "Modified list1: ";
    list.traverse(print_entry);
    cout << endl;

    // E10. void reverse(List &a_list)
    cout << "Test E10 - reverse:" << endl;
    cout << "Original list: ";
    list.traverse(print_entry);
    cout << endl;

    list.reverse(list);
    cout << "Reversed list: ";
    list.traverse(print_entry);
    cout << endl;

    // E11. Error_code split(List &source, List &oddlist, List &evenlist)
    cout << "Test E11 - split:" << endl;
    cout << "Original source list: ";
    list.traverse(print_entry);
    cout << endl;

    result = list.split(list, oddlist, evenlist);
    if (result == success) {
        cout << "Split successful!" << endl;
    } else {
        cout << "Error splitting list!" << endl;
    }
    cout << "Odd list: ";
    oddlist.traverse(print_entry);
    cout << endl;
    cout << "Even list: ";
    evenlist.traverse(print_entry);
    cout << endl;

    // Test full method
    cout << "Test full method:" << endl;
    if (list.full()) {
        cout << "List is full." << endl;
    } else {
        cout << "List is not full." << endl;
    }

    // ####################################  Eercise 2
    cout << "Test full method:" << endl;
    if (list.full()) {
        cout << "List is full." << endl;
    } else {
        cout << "List is not full." << endl;
    }
    // Test replace method
    cout << "Test replace method:" << endl;
    list.insert_first(5);
    list.insert_first(4);
    list.insert_first(3);
    list.insert_first(2);
    list.insert_first(1);
    list.traverse(print_entry); // Print original list
    cout << endl;
    result = list.replace(2, 10); // Replace the entry at position 2 with 10
    if (result == success) {
        cout << "Replacement successful!" << endl;
    } else {
        cout << "Error replacing entry!" << endl;
    }
    list.traverse(print_entry); // Print modified list
    cout << endl;

    // Test remove method
    cout << "Test remove method:" << endl;
    list.traverse(print_entry); // Print original list
    cout << endl;
    result = list.remove(); // Remove an element from the list
    if (result == success) {
        cout << "Removal successful!" << endl;
    } else {
        cout << "Error removing entry!" << endl;
    }
    list.traverse(print_entry); // Print modified list
    cout << endl;

    // Test retrieve method
    cout << "Test retrieve method:" << endl;
    list.traverse(print_entry); // Print original list
    cout << endl;
    result = list.retrieve(removed); // Retrieve an entry from the list
    if (result == success) {
        cout << "Retrieval successful! Retrieved entry: " << removed << endl;
    } else {
        cout << "Error retrieving entry!" << endl;
    }

    // ####################################  Eercise 3

    // Testing singly linked node
    SinglyNode<int> s_node(5);
    std::cout << "Singly Linked Node Data: " << s_node.data << std::endl;

    // Testing doubly linked node
    DoublyNode<double> d_node(3.14);
    std::cout << "Doubly Linked Node Data: " << d_node.data << std::endl;


    return 0;
}