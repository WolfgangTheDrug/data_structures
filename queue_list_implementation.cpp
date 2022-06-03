#include <iostream>

using namespace std;

struct element {
    char character;
    element* next;
};

struct queue {
    element* head;
    element* tail;
}; // implementacja kolejki jako listy

void push(queue q, char value) {
    element* el = new element;
    el -> character = value;
    el -> next = nullptr;
    if(q.tail != nullptr) {
        q.tail -> next = el;
    } else {
        q.head = el;
    }
    q.tail = el;
    cout << "Element " << value << " został dodany do kolejki." << endl;
}

void pop(queue q) {
    element* temp = q.head;
    q.head = q.head -> next;
    delete temp;
    if (q.head == nullptr) {
        q.tail = nullptr;
    }
    cout << "Ostatni element został dodany do stosu." << endl;
}

bool isEmpty(queue q) {
    return q.head==nullptr;
}

int first(queue q) {
    return q.head -> character;
}

int main() {
    queue q;
    q.head = nullptr;
    q.tail = nullptr;

    cout << q.head << endl;

    push(q, '5');
    cout << q.head << endl;

    push(q, '7');
    cout << q.head << endl;

    pop(q);
    cout << q.head << endl;

    cout << boolalpha << isEmpty(q) << endl;

    cout << first(q) << endl;

    return 0;
}
