#include "DoubleVector.h"
#include <stdio.h>


DoubleVector::DoubleVector(){
    m_capacity = 16;
    m_list = new int[16];
    int mid = (m_capacity - 1)/2;
    m_head = mid;              // 7
    m_tail = mid + 1;          // 8

}

DoubleVector::DoubleVector(int n){
    m_capacity = n;
    m_list = new int[n];
    int mid = (m_capacity - 1)/2;
    m_head = mid;
    m_tail = mid + 1;
}

DoubleVector::~DoubleVector(){
    //Normalmente o C++ implementa o destrutor sozinho.
}

int DoubleVector::size(){ return m_size;};
bool DoubleVector::empty(){ return !m_size;};
int DoubleVector::pop_back(){
    if(empty()) return -1;
    m_size--;
    return m_list[--m_tail];
}  
int DoubleVector::pop_front(){
    if(empty()) return -1;
    m_size--;
    return m_list[++m_head];
}
void DoubleVector::push_back(int value){
    if (m_tail == m_capacity)
        shift(0);
    m_list[m_tail++] = value;
    m_size++;

}
void DoubleVector::push_front(int value){
    if (m_head < 0)
        shift(1);
    m_list[m_head--] = value;
    m_size++;
}

int DoubleVector::at(int k){
    return m_list[m_head + k + 1];
}

void DoubleVector::shift(int type){
    if (type){ // to right
        if (m_size == m_capacity){
            resize();
        } else {
            for (int i = m_tail; i > m_head; i--){
                m_list[i] = m_list[i - 1];
            }
            m_tail++;
            m_head--;
        }
    } else {
        if (m_size == m_capacity){
            resize();
        } else {
            for (int i = m_head; i < m_tail; i++){
                m_list[i] = m_list[i + 1];
            }
            m_tail--;
            m_head++;
        }
    }
}
void DoubleVector::resize(){
    int* newMlist = new int [m_capacity*=2];
    int y = m_capacity/4;

    for (int i = m_head + 1; i < m_tail; i++){
        newMlist[y++] = m_list[i];
    }

    m_head = m_capacity/4;
    m_tail = m_capacity/2 + size() + 1;
    print();
    printf ("\n%d e %d\n", m_head, m_tail);
}

void DoubleVector::insert(int value, int k){
    if (m_size == m_capacity) resize();
    for (int i = m_tail; i > m_head + 2 + k; i++){
        m_list[i] = m_list[i - 1];
    }
    m_list[m_head + k + 1] = value;
    m_size++;
    m_tail++;
}
void DoubleVector::replaceAt(int value, int k){
    m_list[m_head + 1 + k] = value;
}
void DoubleVector::removeAt(int k){
    for (int i = m_head + k + 1; i < m_tail - 1; i++)
        m_list[i] = m_list[i + 1];
    m_size--;
    m_tail--;
}
void DoubleVector::removeAll(int value){
    for (int i = 0; i < m_size; i++){
        if (at(i) == value){
            removeAt(i--);
        }
    }
}

void DoubleVector::print(){
    for (int i = m_head + 1; i < m_tail; i++){
        printf ("%d ", m_list[i]);
    }
}
void DoubleVector::printReverse(){
    for (int i = m_tail - 1; i > m_head; i--){
        printf ("%d ", m_list[i]);
    }
}

void DoubleVector::concat(DoubleVector& lst){
    for (int i = lst.m_head + 1; i < lst.m_tail; i++){
        push_back(lst.m_list[i]);
    }
}
bool DoubleVector::equals(DoubleVector& lst){
    int y = m_head + 1;
    for (int i = lst.m_head + 1; i < lst.m_tail; i++){
        if (m_list[y++] != lst.m_list[i]) return false;
    }
    return true;
}