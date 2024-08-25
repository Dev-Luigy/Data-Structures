#ifndef QUEUE_H
#define QUEUE_H

#include <cstddef>
#include "node.h"

template<typename T>
class Queue{
    public:
            Queue();
            ~Queue();
            Queue(const Queue<T>& lst);
    T       pop();
    T       top();
    int     size();
    bool    empty();
    void    clear();
    void    push(T value);

    private:
    Node<T>* m_top {nullptr};
    Node<T>* m_last {nullptr};
    int m_size {0};
};

#include "queue.cpp"

#endif
