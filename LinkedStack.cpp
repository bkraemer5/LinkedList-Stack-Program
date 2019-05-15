#include "LinkedStack.h"

template<class Type>
LinkedStack<Type>::LinkedStack() : head(nullptr) {
}

template<class Type>
LinkedStack<Type>::LinkedStack(const LinkedStack<Type> & aStack) {

  Node<Type> * originalPointer = aStack.head;
    
  if(originalPointer == nullptr) {
      head = nullptr;
  }
  else {
    Node<Type> *prev = nullptr;
    Node<Type> *current = originalPointer->next;
    // reverses the original list
    while(current != nullptr) {
      originalPointer->next = prev;
      prev = originalPointer;
      originalPointer = current;
      current = originalPointer->next;
    }
    // copies original list (reversed) to new list
    while (originalPointer != nullptr) {
      head = new Node<Type>(originalPointer->data, head);
      originalPointer = originalPointer->next;
    }
  }
}

template<class Type>
LinkedStack<Type>::~LinkedStack() {
   delete head->next;
}

template<class Type>
bool LinkedStack<Type>::isEmpty() {
  if(head == nullptr) {
    return true;
  }
  return false;
} 

template<class Type>
bool LinkedStack<Type>::push(Type & newElement) {
  Node<Type> *temp = new Node<Type>;
  temp->data = newElement;
  temp->next = head;
  head = temp;
}

template<class Type>
bool LinkedStack<Type>::pop() {
  Node<Type> *temp = head;
  head = head->next;
  delete temp;
}

template<class Type>
Type LinkedStack<Type>::peek() {
    return head->data;
} 
