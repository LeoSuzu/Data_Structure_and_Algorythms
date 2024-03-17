#ifndef LIST_H
#define LIST_H

typedef int List_entry; // Voit muuttaa List_entryn tarvittaessa toiseksi tietotyypiksi

enum Error_code {
    success,
    overflow,
    underflow
};

struct Node {
    List_entry entry;
    Node *next;

    // Default constructor
    Node() : entry(), next(nullptr) {}

    // Constructor with parameters
    Node(List_entry item, Node *add_on = nullptr) : entry(item), next(add_on) {}
};

class List {
public:
    List();
    ~List();
    bool empty() const;
    Error_code insert_first(const List_entry &x);
    Error_code insert_last(const List_entry &x);
    Error_code remove_first(List_entry &x);
    Error_code remove_last(List_entry &x);
    Error_code remove();
    Error_code median_list(List_entry &x);
    Error_code interchange(int pos1, int pos2);
    void reverse_traverse_list(void (*visit)(List_entry &));
    Error_code copy(List &dest, List &source);
    Error_code join(List &list1, List &list2);
    void reverse(List &a_list);
    Error_code split(List &source, List &oddlist, List &evenlist);
    void traverse(void (*visit)(List_entry &));
    void clear();
    bool full();
    Error_code replace(int position, const List_entry &x);
    Error_code retrieve(List_entry &x);

private:
    Node *head;
    int count;
    Node *set_position(int position) const;

};

#endif // LIST_H
