#ifndef _LINKED_STACK
#define _LINKED_STACK

template<class Type>
class Node {
    public:
        Type data;
        Node<Type> * next = nullptr;
};

template<class Type>
class LinkedStack {

private:
    Node<Type> * head; // Points to first node of list

public:
    // Constructors and destructors
    LinkedStack();    // Default constructor
    LinkedStack(const LinkedStack<Type> & aStack);  // Copy constructor
    ~LinkedStack();   // Destructor

    // Stack operations
    bool isEmpty();
    bool push(Type & newElement);
    bool pop();
    Type peek();
}; // end LinkedStack

#include "LinkedStack.cpp"
#endif
