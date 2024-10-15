#ifndef NODEH
#define NODEH

template <class T> class Node {
public:
  Node();
  Node(T value);
  Node(Node<T> *before, Node<T> *next, T value);

  // methods
  // Setters
  void setNext(Node<T> *newNext);
  void setBefore(Node<T> *newBefore);
  void setValue(T value);

  // Getters
  Node<T> *getNext();
  Node<T> *getBefore();
  T getValue();

private:
  T value;
  Node<T> *before{nullptr};
  Node<T> *next{nullptr};
};

#endif // !NODEH
