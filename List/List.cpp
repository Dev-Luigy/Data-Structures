#include "List.h"
#include <cstddef>
#include <iostream>

List::List() {
  sentinel = nullptr;
  endSentinel = nullptr;
}

List::~List() {}

void List::add(int value) {
  Node *newNode = new Node(value, nullptr, nullptr);
  if (empty()) {
    sentinel = endSentinel = newNode;
  } else {
    newNode->setNext(sentinel);
    newNode->setPrev(endSentinel);
    endSentinel->setNext(newNode);
    endSentinel = newNode;
  }
  mSize++;
}

int List::removeNode(int k) {
  if (k > mSize - 1 || k < 0)
    return -1;
  if (mSize == 1) {
    mSize--;
    delete (sentinel);
    sentinel = nullptr;
    endSentinel = nullptr;
    return 0;
  }
  Node *iterator = sentinel;
  int i = 0;
  while (i++ < k - 1) {
    iterator = iterator->getNext();
  }
  Node *temp = iterator->getNext();
  int value = temp->getValue();
  delete (temp);
  return value;
}

int List::at(int k) {
  Node *iterator = sentinel;
  int i = 0;
  while (i++ < k)
    iterator = iterator->getNext();

  return iterator->getValue();
}

bool List::empty() { return !mSize; }

int List::getSize() { return mSize; }
