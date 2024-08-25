#ifndef NODE_CPP
#define NODE_CPP

#include "node.h"

template<typename T>
Node<T>::Node(T value, Node<T>* next) : value(value), next(next){}
template<typename T>
T Node<T>::getValue(){
    return value;
}
template<typename T>
Node<T>* Node<T>::getNext(){
    return next;
}
template<typename T>
void Node<T>::setValue(T newValue){
    next = newValue;
}
template<typename T>
void Node<T>::setNext(Node<T>* newNext){
    next = newNext;
}

#endif