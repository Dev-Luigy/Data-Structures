#ifndef NODE_H
#define NODE_H

class Node {
private:
  int value{0};
  Node *next{nullptr};
  Node *prev{nullptr};

public:
  Node(int value, Node *next, Node *prev);
  int getValue();
  void setValue(int value);
  Node *getNext();
  Node *getPrev();
  void setNext(Node *next);
  void setPrev(Node *prev);
};

#endif // NODE_H
