#include <iostream>
#include "Vector.h"

using namespace std;

int main() {
  cout << "Hello, World!" << endl;

  Vector a;
  Vector b(5);
  Vector c(3,4,5);

  a.Print();
  b.Print();
  c.Print();

  a = b*c;

  a = b;
  a.operator=(b); //same thing^

  return 0;
}