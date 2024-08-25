#ifndef QUEUE_CPP
#define QUEUE_CPP
#include "node.h"
#include "queue.h"
#include "stdexcept"
#include <stdio.h>

using namespace std;

template<typename T>
Queue<T>::Queue(){
    m_top = nullptr;
    m_last = nullptr;
    m_size = 0;
}
template<typename T>
Queue<T>::Queue(const Queue<T>& lst){
    Node<T>* aux = lst.m_top;
    m_top = aux;
    while(size() != lst.size()){
        while(aux->getNext()!= nullptr){
            aux = aux->getNext();
            push(aux->getValue);
        }   
    }    
}
template<typename T>
Queue<T>::~Queue(){

}
template<typename T>
int Queue<T>::size(){
    return m_size;
}
template<typename T>
bool Queue<T>::empty(){
    if(m_size == 0) return true;
    return false;
}
template<typename T>
void Queue<T>::clear(){
    while(m_size > 0){
        pop();
    }
}
template<typename T>
void Queue<T>::push(T value){
    Node<T>* element = new Node<T>(value, nullptr);
    if(empty()){
        m_last = element;
        m_top = element;
    }
    else{
        Node<T>* aux = m_last;
        aux->setNext(element);
        m_last = element;
    }
    m_size++;
}
template<typename T>
T Queue<T>::pop(){
    if(empty()) throw std :: runtime_error("Empty queue.");
    else{
        Node<T>* aux = m_top;
        T valor = m_top->getValue();
        m_top = aux->getNext();
        delete aux;
        m_size--;
        return valor;
    }
}
#endif
