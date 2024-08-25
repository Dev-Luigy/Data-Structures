#include <cstdlib>
#include <stdlib.h>
#include <stdio.h>
#include "ForwardList.h"
#include "Node.h"

// construtor: cria lista vazia
ForwardList::ForwardList(){
    m_head = nullptr;
    m_size = 0;
}

ForwardList::ForwardList(ForwardList& lst){
    Node* lstHead = lst.m_head;
    auto alocHeadNode = [this, lstHead]{
        m_head = (Node *) malloc (sizeof(Node));
        m_head->setValue(lstHead->getValue());
        m_head->setNext(lstHead->getNext());
    };

    if (empty())
        alocHeadNode();
    Node* iterator = m_head;
    while (lstHead){
        push_back(lstHead->getValue());
        lstHead = lstHead->getNext();
    }
}

ForwardList::~ForwardList(){}

int ForwardList::size() const{
    return m_size;
}

bool ForwardList::empty() const{
    return !m_size;
}

void ForwardList::clear(){
    Node* iterator = m_head; // first value;
    while(iterator->getNext()){
        Node* temp = iterator;
        iterator = iterator->getNext();
        free (temp);
    }
    free(iterator); //last value
}

int ForwardList::at(int k) const{
    Node* iterator = m_head;
    int i = 0;
    while (i++ < k){
        iterator = iterator->getNext();
    }
    return iterator->getValue();
}

void ForwardList::push_back(int value){
    if (empty()){
        m_head = new Node(value, nullptr);
        m_size++;
        return;
    }

    Node* temp = getNode(m_size++ - 1);
    temp->setNext(new Node(value, nullptr));
}


void ForwardList::insert(int value, int k){
    if (k == 0) { 
        push_front(value);
        return;
    }

    Node* iterator = m_head->getNext();
    
    int i = 1;
    while (i++ < k - 1){
        iterator = iterator->getNext();
    }

    iterator->setNext(new Node(value, iterator->getNext()));
    m_size++;
}

void ForwardList::removeAt(int k){
    Node* temp = getNode(k - 1);
    Node* toDell = temp->getNext();
    temp->setNext(toDell->getNext());
    free(toDell);
    m_size--;
}

Node* ForwardList::getNode(int k){
    Node* iterator = m_head;
    int i = 0;
    while(i++ < k){
        iterator = iterator->getNext();
    }
    return iterator;
}

void ForwardList::replaceAt(int value, int k){
    Node* temp = getNode(k);
    temp->setValue(value);
}

void ForwardList::removeAll(int value){
    if (empty()) return;
    if (m_head->getValue() == value) pop_front();
    Node* iterator = m_head->getNext();
    int i = 1;
    while(iterator->getNext()){
        if (iterator->getValue() == value){
            removeAt(i--);
            iterator = getNode(i);
            continue;
        }
        iterator = iterator->getNext();
        i++;
    }
    if (iterator->getValue() == value) pop_back();
}

void ForwardList::push_front(int value){
    Node* temp = m_head;
    m_head = new Node(value, temp);
    m_size++;
}

int ForwardList::pop_back() {
    if (empty()) return 0;
    Node* iterator = m_head;
    if (!iterator->getNext()) {
        // Handle the case where the list has only one node
        int value = iterator->getValue();
        free(iterator);
        m_head = nullptr;
        m_size = 0;
        return value;
    }
    while (iterator->getNext()->getNext()) {
        iterator = iterator->getNext();
    }
    Node* temp = iterator->getNext();
    int value = temp->getValue();
    free(temp);
    iterator->setNext(nullptr);
    m_size--;
    return value;
}

int ForwardList::pop_front(){
    if (empty()) return 0;
    Node* temp = m_head;
    int value = temp->getValue();
    m_head = m_head->getNext();
    free(temp);
    m_size--;
    return value;
}

bool ForwardList::equals(ForwardList& lst){
    Node* lstHead = lst.m_head;
    Node* iterator = m_head;

    while(iterator){
        if (iterator->getValue() != lstHead->getValue()) return false;
        iterator = iterator->getNext();
        lstHead = lstHead->getNext();
    }
    return true;
}

void ForwardList::concat(ForwardList& lst){
    if (empty()){
        push_back(lst.m_head->getValue());
    }

    Node* lstHead = lst.m_head;
    Node* iterator = m_head;

    while(iterator->getNext()){
        iterator = iterator->getNext();
    }

    while(lstHead->getNext()){
        push_back(lstHead->getValue());
        lstHead = lstHead->getNext();
    }
}

void ForwardList::remove_duplicates(){
    for (int i = 0; i < m_size; i++){
        Node* atualValue = getNode(i);
        for (int j = i + 1; j < m_size; j++){
            Node* toComparate = getNode(j);
            if (atualValue->getValue() == toComparate->getValue()){
                removeAt(j);
                j--;
            }
        }
    }
}