#include "List.h"
#include <iostream>

using namespace std;

// g++ main.cpp List.cpp Node.cpp -o myProgram && ./myProgram

int main() {
  List snake;
  snake.add(5);
  for (int i = 0; i < snake.getSize(); i++) {
    cout << snake.at(i) << endl;
  }
  snake.removeNode(0);
  return 0;
}
