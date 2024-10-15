#ifndef DOUBLELINKEDLISTH
#define DOUBLELINKEDLISTH
#include "Node.h"

template <class T> class DoubleLinkedList {
public:
  DoubleLinkedList();
  DoubleLinkedList(Node<T> *head);
  DoubleLinkedList(Node<T> *head, Node<T> *tail);
  ~DoubleLinkedList();
  void add(Node<T> *newValue);
  void insert(T value, int index);
  void insert(Node<T> *newNode, int index);
  void concatLists(DoubleLinkedList<T> &list);
  bool equalsList(DoubleLinkedList<T> &list);
  Node<T> *find(T value);
  void deleteFirstValue(T value);
  void deleteAllValue(T value);
  void editFirstValue(T oldValue, T newValue);
  void editAllValue(T oldValue, T newValue);
  Node<T> *pop_back();
  Node<T> *pop_front();
  Node<T> *front();
  Node<T> *back();
  Node<T> *at(int index);
  void editAt(int index);
  int getSize();
  void clear();
  bool isEmpty();

private:
  Node<T> *first{nullptr};
  Node<T> *last{nullptr};
  int size{0};
};

#endif // !DOUBLELINKEDLISTH
