#ifndef STACK_H
#define STACK_H

#include <cstddef>
#include "node.h"

template<typename T>
class Stack{
    public:
            Stack();
            ~Stack();
            Stack(const Stack<T>& lst);
    T       pop();
    T       top();
    int     size();
    bool    empty();
    void    clear();
    void    push(T value);

    private:
    Node<T>* m_top {nullptr};
    int m_size{0};
};

#include "stack.cpp"

#endif