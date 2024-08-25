#include <cstddef>
#include <stdio.h>
#include <stdlib.h>
#include "Vector.h"
#include <cstring>

Vector::Vector(){
    m_capacity = 16;
    m_list = (int *) malloc (sizeof(int) * m_capacity);
} 

Vector::Vector(int n){
    m_capacity = n;
    m_list = (int *) malloc (sizeof(int) * m_capacity);
}

Vector::Vector(const Vector& vector){
    m_size = vector.m_size;
    m_capacity = vector.m_capacity;
    m_list = new int[m_capacity];
    memcpy(m_list, vector.m_list, sizeof(int) * m_size);
}

Vector::~Vector(){
    //free(this);
}

int Vector::capacity() const{
    return m_capacity;
}

int Vector::size() const{
    return m_size;
}

bool Vector::empty() const{
    return !m_size;
}

int Vector::at(int k) const{
    return k > m_size ? -1 : m_list[k];
}

void Vector::resize(int n){
    if (n > m_capacity) m_capacity = n;
    if (n < m_size) m_size = n;
    m_list = (int*) realloc(m_list, n * sizeof(int));
}

void Vector::push_back(int value){
    if (m_size == m_capacity - 1) resize(m_capacity * 2);
    m_list[m_size++] = value;
}

int Vector::pop_back(){
    if (empty()){
        return -1 ;
    }
    return m_list[--m_size];
}

void Vector::replaceAt(int value, int k){
    this->m_list[k] = value;
}

void Vector::removeAt(int k){
    if (k >= m_size || k < 0) return;
    for (int i = k; i < m_size - 1; i++){
        m_list[i] = m_list[i + 1]; 
    }
    m_size--; // update the size of the Vector
}

void Vector::insert(int value, int k){
    if (k >= m_capacity || k < 0) return;
    for(int i = ++m_size; i >= k ; i--){
        m_list[i] = m_list[i - 1];
    }
    m_list[k - 1] = value;
}

// Remove todas as ocorrências do elemento value na lista.
void Vector::removeAll(int value){
    for (int i = 0; i < m_size; i++){
        if (m_list[i] == value) {
            removeAt(i);
            i -= 1;
        }
    }
}

//Semelhante a função push_back só que adiciona
// o elemento na primeira posição
void Vector::push_front(int value){
    if (m_size + 1 == m_capacity) resize(m_capacity * 2);
    if (m_size < m_capacity) 
        memmove(&m_list[1], &m_list[0], sizeof(int) * ++m_size);
    m_list[0] = value;
}  

//Semelhante a função pop_back só que remove e retorna o primeiro elemento
// se a lista nao estiver vazia. Caso contrario, retorna -1 
int Vector::pop_front(){
    if (empty()) return - 1;
    int aux = m_list[0];
    memmove(&m_list[0], &m_list[1], sizeof(int) * --m_size);
    return aux;
}

void Vector::remove_duplicates(){
    int idxAtual = 0;
    while(idxAtual < m_size){
        for(int i = idxAtual + 1; i < this->m_size; i++){
            if (this->at(i) == this->at(idxAtual)){
                removeAt(i);
                i--;
            }
        }
        idxAtual++;
    }
}