#ifndef NODE_H
#define NODE_H

template <typename T>
class Node{
    public:
                Node(T value, Node<T>* next);
    T           getValue();
    Node<T>*    getNext();
    void        setValue(T newValue);
    void        setNext(Node<T>* newNext);

    private:
    T value;
    Node<T>* next {nullptr};
};

#include "node.cpp"
#endif
