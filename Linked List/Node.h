#ifndef NODE_H
#define NODE_H

class Node {
private:
    int value;  // valor 
    Node* next;  // ponteiro para o proximo no 
public:
    /**
     * Construtor que recebe o valor que o nó irá armazenar e o ponteiro para o 
     * próximo nó da lista.
     * */
    Node(int val, Node *nextPtr);
    
    /**
    Métodos gets e sets dos atributos
    **/
    int getValue();
    Node* getNext();
    void setValue(int newValue);
    void setNext(Node* newNext);
};

#endif
