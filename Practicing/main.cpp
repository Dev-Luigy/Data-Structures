#include <iostream>
#include <stdlib.h>

using namespace std;

// Structs
struct Recongle {
  int length; // Int have 4 bytes in C++
  int breadth;
  char x; // will get 4 bytes but only use 1.
} typedef Recongle;

int main() {
  // Struct {
  //    Recongle a = {10, 5};
  //    std::cout << sizeof(a);
  //
  // }

  // Pointers {
  // int a = 10;
  // int *p = &a;
  // *p += 10;
  // cout << a << endl;
  //
  // Array Example.
  // int A[5] = {2, 4, 6, 8, 10};
  // int *p = A;
  // for (int i = 0; i < 5; ++i)
  //   cout << p[i] << endl;
  //
  // Malloc Example.
  // int *p = (int *)malloc(5 * sizeof(int));
  // for (int i = 0; i < 5; ++i)
  //   cin >> p[i];
  // for (int i = 0; i < 5; ++i)
  //   cout << p[i];
  // free(p);
  //
  // Dynamic Example.
  // int *p = new int(5);
  // for (int i = 0; i < 5; ++i)
  //   cin >> p[i];
  // for (int i = 0; i < 5; ++i)
  //   cout << p[i];
  // delete[] p;
  //
  // References {
  //  int a = 10;
  //  int &r = a;
  //  r++;
  //  cout << r << endl;
  //
  //  Rectangle r = {10, 5};
  //  cout << r.lenght << endl;
  //  cout << r.breadth << endl;
  //
  //  Rectangle *p = &r;
  //  cout << p->length << endl;
  //  cout << p->breadth << endl;
}
