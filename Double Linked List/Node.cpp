#include "Node.h"
#ifndef NODECPP
#define NODECPP

template <class T> Node<T>::Node(){};
template <class T> Node<T>::Node(T value) : value(value) {}
template <class T>
Node<T>::Node(Node<T> *before, Node<T> *next, T value)
    : value(value), before(before), next(next){};

// methods
// Setters
template <class T> void Node<T>::setNext(Node<T> *newNext) {
  this->next = newNext;
};
template <class T> void Node<T>::setBefore(Node<T> *newBefore) {
  this->before = newBefore;
}
template <class T> void Node<T>::setValue(T value) { this->value = value; }

// Getters
template <class T> Node<T> *Node<T>::getNext() { return this->next; };
template <class T> Node<T> *Node<T>::getBefore() { return this->before; };
template <class T> T Node<T>::getValue() { return this->value; };

#endif // !NODECPP
