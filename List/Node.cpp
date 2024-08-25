#include "Node.h"

Node::Node(int value, Node *next, Node *prev)
    : value(value), next(next), prev(prev) {}

int Node::getValue() { return value; }
void Node::setValue(int value) { this->value = value; }
Node *Node::getNext() { return next; }
Node *Node::getPrev() { return prev; }
void Node::setNext(Node *next) { this->next = next; }
void Node::setPrev(Node *prev) { this->prev = prev; }
