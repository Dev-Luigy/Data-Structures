#ifndef DOUBLELINKEDLISTCPP
#define DOUBLELINKEDLISTCPP

#include "DoubleLinkedList.h"

template <typename T> DoubleLinkedList<T>::DoubleLinkedList() {}
template <typename T> DoubleLinkedList<T>::DoubleLinkedList(Node<T> *head) {
  this->first = head;
  this->size++;
};
template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(Node<T> *head, Node<T> *tail) {
  this->first = head;
  this->last = tail;

  first->setNext(tail);
  last->setBefore(first);

  size += 2;
};
template <typename T> DoubleLinkedList<T>::~DoubleLinkedList() {
  delete (this);
};

template <typename T> void DoubleLinkedList<T>::add(Node<T> *newValue) {
  if (!this->isEmpty()) {
    newValue->setBefore(this->last);
    this->last->setNext(newValue);
    this->last = newValue;
  } else {
    this->first = newValue;
    this->last = newValue;
  }
}

template <typename T> void DoubleLinkedList<T>::insert(T value, int index) {
  if (index < 0 || index > getSize()) {
    return;
  }

  Node<T> *newNode = new Node<T>(nullptr, nullptr, value);

  if (index == 0) { // Insert at the beginning (O(1))
    newNode->setNext(this->first);
    if (this->first != nullptr) {
      this->first->setBefore(newNode);
    }
    this->first = newNode;
    if (this->last == nullptr) { // List was empty
      this->last = newNode;
    }
  } else if (index == getSize()) { // Insert at the end (O(1))
    newNode->setBefore(this->last);
    if (this->last != nullptr) {
      this->last->setNext(newNode);
    }
    this->last = newNode;
    if (this->first == nullptr) { // List was empty
      this->first = newNode;
    }
  } else {
    Node<T> *temp;
    if (index < getSize() / 2) { // Start from the beginning
      temp = this->first;
      for (int i = 0; i < index - 1; ++i) {
        temp = temp->getNext();
      }
    } else { // Start from the end
      temp = this->last;
      for (int i = getSize() - 1; i > index; --i) {
        temp = temp->getBefore();
      }
    }

    newNode->setNext(temp->getNext());
    newNode->setBefore(temp);
    if (temp->getNext() != nullptr) {
      temp->getNext()->setBefore(newNode);
    }
    temp->setNext(newNode);
  }

  ++size; // Increment the size of the list
}

template <typename T>
void DoubleLinkedList<T>::insert(Node<T> *newNode, int index) {};
template <typename T>
void DoubleLinkedList<T>::concatLists(DoubleLinkedList<T> &list) {};
template <typename T>
bool DoubleLinkedList<T>::equalsList(DoubleLinkedList<T> &list) {};
template <typename T> Node<T> *DoubleLinkedList<T>::find(T value) {};
template <typename T> void DoubleLinkedList<T>::deleteFirstValue(T value) {};
template <typename T> void DoubleLinkedList<T>::deleteAllValue(T value) {};
template <typename T>
void DoubleLinkedList<T>::editFirstValue(T oldValue, T newValue) {};
template <typename T>
void DoubleLinkedList<T>::editAllValue(T oldValue, T newValue) {};
template <typename T> Node<T> *DoubleLinkedList<T>::pop_back() {};
template <typename T> Node<T> *DoubleLinkedList<T>::pop_front() {};
template <typename T> Node<T> *DoubleLinkedList<T>::front() {};
template <typename T> Node<T> *DoubleLinkedList<T>::back() {};
template <typename T> Node<T> *DoubleLinkedList<T>::at(int index) {};
template <typename T> void DoubleLinkedList<T>::editAt(int index) {};
template <typename T> int DoubleLinkedList<T>::getSize() {};
template <typename T> void DoubleLinkedList<T>::clear() {};
template <typename T> bool DoubleLinkedList<T>::isEmpty() {};

#endif // !DOUBLELINKEDLISTCPP
