#ifndef STACK_CPP
#define STACK_CPP
#include <stdexcept>

#include "stack.h"

template <typename T>
Stack<T>::Stack() : m_top(nullptr){}
template <typename T>
Stack<T>::~Stack(){
    clear();
}

template <typename T>
Stack<T>::Stack(const Stack<T>& lst) {
    Node<T>* aux = lst.m_top;
    Stack<T> stackAux;
    while (aux) {
        stackAux.push(aux->getValue());
        aux = aux->getNext();
    }
    Node<T>* newAux = stackAux.m_top;
    while (newAux){
        push(newAux->getValue());
        newAux = newAux->getNext();
    }
    stackAux.clear();
}

template <typename T>
T Stack<T>::pop(){
    if (empty())
        throw std::runtime_error("Stack is empty");
    T value = m_top->getValue();
    Node<T>* temp = m_top;
    m_top = m_top->getNext();
    free(temp);
    m_size--;
    return value;
}

template <typename T>
T Stack<T>::top(){
    return m_top->getValue();
}

template <typename T>
int Stack<T>::size(){
    return m_size;
}

template <typename T>
bool Stack<T>::empty(){
    return !m_size;
}

template <typename T>
void Stack<T>::clear(){
    while(!empty())
        pop();
}

template <typename T>
void Stack<T>::push(T value){
    m_top = new Node<T>(value, m_top);
    m_size++;
}

#endif