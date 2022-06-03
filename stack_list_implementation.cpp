#include <iostream>
using namespace std;

struct element {
    int number;
    element* next;
}; // implementacja stosu jako listy

void push(element* & stack, int value) {
    element* el = new element;
    el -> number = value;
    el -> next = stack;
    stack = el;
    cout << "Element " << value << " został dodany do stosu." << endl;
}

void pop(element* & stack) {
    element* temp = stack;
    stack = stack -> next;
    delete temp;
    cout << "Ostatni element został dodany do stosu." << endl;
}

bool isEmpty(element* stack) {
    return stack==nullptr;
}

int top(element* stack) {
    return stack -> number;
}


int main() {
    element* stack = nullptr; // inicjacja zmiennej przechowującej wierzchołek stosu
    cout << stack << endl;

    push(stack, 5);
    cout << stack << endl;

    push(stack, 7);
    cout << stack << endl;

    pop(stack);
    cout << stack << endl;

    cout << boolalpha << isEmpty(stack) << endl;

    cout << top(stack) << endl;

    return 0;
}
