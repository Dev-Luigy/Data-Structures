#include "queue.cpp"
#include "stack.cpp"
#include <iostream>

using namespace std;

int main() {
  Stack<int> pilha;
  Queue<int> fila;

  pilha.push(1);
  pilha.push(2);
  pilha.push(3);
  cout << pilha.pop();
  fila.push(5);
  cout << fila.pop();
}
