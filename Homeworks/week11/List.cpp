#include "List.h"

List::List() {
    head = nullptr;
    count = 0;
}

List::~List() {
    Node *temp;
    while (head != nullptr) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

// (C)
bool List::empty() const {
    return count == 0;
}

Error_code List::insert_first(const List_entry &x) {
    Node *new_node = new Node(x, head);
    if (new_node == nullptr)
        return overflow;
    head = new_node;
    count++;
    return success;
}

// (b
void List::clear() {
    Node *current = head;
    while (current != nullptr) {
        Node *temp = current;
        current = current->next;
        delete temp;
    }
    head = nullptr;
    count = 0;
}


Error_code List::insert_last(const List_entry &x) {
    Node *new_node = new Node(x);
    if (new_node == nullptr)
        return overflow;
    if (empty())
        head = new_node;
    else {
        Node *temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = new_node;
    }
    count++;
    return success;
}

Error_code List::remove_first(List_entry &x) {
    if (count == 0)
        return underflow;
    x = head->entry;
    Node *old_head = head;
    head = head->next;
    delete old_head;
    count--;
    return success;
}

Error_code List::remove_last(List_entry &x) {
    if (empty())
        return underflow;
    Node *temp = head;
    if (head->next == nullptr) {
        x = head->entry;
        delete head;
        head = nullptr;
    } else {
        while (temp->next->next != nullptr)
            temp = temp->next;
        x = temp->next->entry;
        delete temp->next;
        temp->next = nullptr;
    }
    count--;
    return success;
}

Error_code List::median_list(List_entry &x) {
    if (empty())
        return underflow;
    int median_position = count / 2;
    if (count % 2 == 0) // Even number of entries
        median_position--; // Adjust to left-central entry
    Node *current = set_position(median_position);
    x = current->entry;
    return success;
}

Error_code List::interchange(int pos1, int pos2) {
    if (pos1 < 0 || pos2 < 0 || pos1 >= count || pos2 >= count)
        return overflow;
    if (pos1 == pos2)
        return success;
    Node *node1 = set_position(pos1);
    Node *node2 = set_position(pos2);
    List_entry temp = node1->entry;
    node1->entry = node2->entry;
    node2->entry = temp;
    return success;
}

void List::reverse_traverse_list(void (*visit)(List_entry &)) {
    Node *current = head;
    while (current != nullptr) {
        Node *next_node = current->next;
        visit(current->entry);
        current = next_node;
    }
}

Error_code List::copy(List &dest, List &source) {
    if (&dest == this)
        return overflow; // Attempting to copy to itself
    dest.clear(); // Clear destination list
    Node *current = head;
    while (current != nullptr) {
        Error_code result = dest.insert_last(current->entry);
        if (result != success)
            return result;
        current = current->next;
    }
    return success;
}

Error_code List::join(List &list1, List &list2) {
    Node *current = list2.head;
    while (current != nullptr) {
        Error_code result = insert_last(current->entry);
        if (result != success)
            return result;
        current = current->next;
    }
    return success;
}

void List::reverse(List &a_list) {
    Node *prev = nullptr;
    Node *current = head;
    Node *next_node;
    while (current != nullptr) {
        next_node = current->next;
        current->next = prev;
        prev = current;
        current = next_node;
    }
    head = prev;
}

Node *List::set_position(int position) const {
    Node *temp = head;
    for (int i = 0; i < position; i++)
        temp = temp->next;
    return temp;
}

void List::traverse(void (*visit)(List_entry &)) {
    Node *current = head;
    while (current != nullptr) {
        visit(current->entry);
        current = current->next;
    }
}

Error_code List::split(List &source, List &oddlist, List &evenlist) {
    if (&oddlist == this || &evenlist == this)
        return overflow; // Attempting to split to itself

    // Clear oddlist and evenlist
    oddlist.clear();
    evenlist.clear();

    Node *current = source.head;
    int position = 0;
    while (current != nullptr) {
        if (position % 2 == 0) // Even position
            evenlist.insert_last(current->entry);
        else // Odd position
            oddlist.insert_last(current->entry);
        current = current->next;
        position++;
    }
    return success;
}

// a, b, c is already done in above
bool List::full() {
    Node* new_node = new Node(); // Attempt to allocate memory
    if (new_node == nullptr) {
        // Memory allocation failed, list is considered full
        return true;
    } else {
        // Memory allocation succeeded, deallocate memory and return false
        delete new_node;
        return false;
    }
}
Error_code List::replace(int position, const List_entry &x) {
    if (position < 0 || position >= count)
        return overflow; // Invalid position

    Node *current = set_position(position);
    current->entry = x;
    return success;
}
Error_code List::remove() {
    if (count == 0) // If the list is empty, return underflow
        return underflow;

    if (count % 2 == 0) { // If the count is even, remove the last element
        Node *temp = head;
        Node *prev = nullptr;
        while (temp->next != nullptr) {
            prev = temp;
            temp = temp->next;
        }
        if (prev == nullptr) {
            // If the list only contains one element
            delete head;
            head = nullptr;
        } else {
            prev->next = nullptr;
            delete temp;
        }
    } else { // If the count is odd, remove the first element
        Node *old_head = head;
        head = head->next;
        delete old_head;
    }
    count--;
    return success;
}

Error_code List::retrieve(List_entry &x) {
    if (empty())
        return underflow; // List is empty, cannot retrieve last element

    Node *temp = head;
    // Traverse the list until the last node
    while (temp->next != nullptr)
        temp = temp->next;

    // Now 'temp' points to the last node
    x = temp->entry; // Retrieve the entry of the last node
    return success;
}
