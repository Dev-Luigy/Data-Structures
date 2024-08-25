#ifndef LIST_H
#define LIST_H

#include "Node.h"

class List {
private:
  int mSize{0};
  Node *sentinel;
  Node *endSentinel;

public:
  List();
  ~List();
  void add(int value);
  int removeNode(int k);
  int at(int k);
  bool empty();
  int getSize();
};

#endif // LIST_H
