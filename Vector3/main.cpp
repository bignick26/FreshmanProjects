#include <iostream>
#include "Vector.h"

using namespace std;

int main() {

  //write code to test your implementations here

  //each function must be tested at least 2x

  Vector a(1);
  Vector b(2);
  Vector c(1,2,3);
  Vector d(-10,3,8);
  Vector e(-40,69,23);

  cout << "A: ";
  a.Print();
  cout << "B: ";
  b.Print();
  cout << "C: ";
  c.Print();
  cout << "D: ";
  d.Print();
  cout << "E: ";
  e.Print();

  cout << endl << "Calculations: " << endl;
  Vector ans;
  float ans1;
  bool ans2;

  //Cross Product
  ans = a^b;
  cout << "A cross B: ";
  ans.Print();
  if(ans.X != 0 || ans.Y != 0 || ans.Z != 0) {
    std::cout << "TEST FAILED ON Cross Product" << std::endl;
  }

  ans = b^c;
  cout << "B cross C: ";
  ans.Print();
  if(ans.X != 2 || ans.Y != -4 || ans.Z != 2) {
    std::cout << "TEST FAILED ON Cross Product" << std::endl;
  }

  //Cross Product static
  ans = ans.crossProduct(a,b);
  cout << "static A cross B: ";
  ans.Print();
  if(ans.X != 0 || ans.Y != 0 || ans.Z != 0) {
    std::cout << "TEST FAILED ON static Cross Product" << std::endl;
  }


  ans = ans.crossProduct(b,c);
  cout << "static B cross C: ";
  ans.Print();
  if(ans.X != 2 || ans.Y != -4 || ans.Z != 2) {
    std::cout << "TEST FAILED ON static Cross Product" << std::endl;
  }


  //Dot Product
  ans1 = a|b;
  cout << "A dot B: " << ans1 << endl;
  if(ans1!=6) {
    std::cout << "TEST FAILED ON Dot Product" << std::endl;
  }


  ans1 = b|c;
  cout << "B dot C: " << ans1 << endl;
  if(ans1!=12) {
    std::cout << "TEST FAILED ON Dot Product" << std::endl;
  }

  //Dot Product static
  ans1 = a.dotProduct(a,b);
  cout << "static A dot B: " << ans1 << endl;
  if(ans1!=6) {
    std::cout << "TEST FAILED ON Dot Product" << std::endl;
  }

  ans1 = b.dotProduct(b,c);
  cout << "static B dot C: " << ans1 << endl;
  if(ans1!=12) {
    std::cout << "TEST FAILED ON Dot Product" << std::endl;
  }

  //Addition
  ans = a+b;
  cout << "A plus B: ";
  ans.Print();
  if(ans.X != 3 || ans.Y != 3 || ans.Z != 3) {
    std::cout << "TEST FAILED ON Addition" << std::endl;
  }


  ans = b+c;
  cout << "B plus C: ";
  ans.Print();
  if(ans.X != 3 || ans.Y != 4 || ans.Z != 5) {
    std::cout << "TEST FAILED ON Addition" << std::endl;
  }

  //Subtraction
  ans = a-b;
  cout << "A minus B: ";
  ans.Print();
  if(ans.X != -1 || ans.Y != -1 || ans.Z != -1) {
    std::cout << "TEST FAILED ON Subtraction" << std::endl;
  }


  ans = b-c;
  cout << "B minus C: ";
  ans.Print();
  if(ans.X != 1 || ans.Y != 0 || ans.Z != -1) {
    std::cout << "TEST FAILED ON Subtraction" << std::endl;
  }

  //Scaling Multiplication
  ans = a*5;
  cout << "A *scale 5: ";
  ans.Print();
  if(ans.X != 5 || ans.Y != 5 || ans.Z != 5) {
    std::cout << "TEST FAILED ON Scaled Multiplication" << std::endl;
  }

  ans =b*3;
  cout << "B *scale 3: ";
  ans.Print();
  if(ans.X != 6 || ans.Y != 6 || ans.Z != 6) {
    std::cout << "TEST FAILED ON Scaled Multiplication" << std::endl;
  }

  //Multiplication
  ans = a*b;
  cout << "A times B: ";
  ans.Print();
  if(ans.X != 2 || ans.Y != 2 || ans.Z != 2) {
    std::cout << "TEST FAILED ON Multiplication" << std::endl;
  }

  ans = b*c;
  cout << "B times C: ";
  ans.Print();
  if(ans.X != 2 || ans.Y != 4 || ans.Z != 6) {
    std::cout << "TEST FAILED ON Multiplication" << std::endl;
  }

  //Scaling Division
  ans = a/5;
  cout << "A /scale 5: ";
  ans.Print();
  if(ans.X != (float)(0.2) || ans.Y != (float)(0.2) || ans.Z != (float)(0.2)) {
    std::cout << "TEST FAILED ON Scaled Division" << std::endl;
  }

  ans =b/3;
  cout << "B /scale 3: ";
  ans.Print();
  if(ans.X != (float)(0.666667) || ans.Y != (float)(0.666667) || ans.Z != (float)(0.666667)) {
    std::cout << "TEST FAILED ON Scaled Division (check b/c potential rounding error)" << std::endl;
  }

  //Division
  ans = a/b;
  cout << "A divide B: ";
  ans.Print();
  ans = a/5;
  cout << "A /scale 5: ";
  ans.Print();
  if(ans.X != (float)(0.5) || ans.Y != (float)(0.5) || ans.Z != (float)(0.5)) {
    std::cout << "Testing Manually cause rounding errors are bothering me...." << std::endl;
  }

  ans = b/c;
  cout << "B divide C: ";
  ans.Print();

  //Boolean equals
  ans2 = a==(b/2);
  cout << "A == B/2: " << ans2 << endl;

  ans2 = b==c;
  cout << "B == C: " << ans2 << endl;

  //Boolean not equals
  ans2 = a!=(b/2);
  cout << "A != B/2: " << ans2 << endl;

  ans2 = b!=c;
  cout << "B != C: " << ans2 << endl;

  //Short cut component add
  a+=b;
  cout << "A += B: ";
  a.Print();

  a+=c;
  cout << "A += C: ";
  a.Print();

  //Short cut component subtraction
  a-=b;
  cout << "A -= B: ";
  a.Print();

  a-=c;
  cout << "A -= C: ";
  a.Print();

  //Short cut scale division/multiplication
  a/=3;
  cout << "A /= 3: ";
  a.Print();
  a*=(3);
  cout << "A *= 3: ";
  a.Print();
  c/=4;
  cout << "C /= 4: ";
  c.Print();
  c*=4;
  cout << "C *= 4: ";
  c.Print();

  //Indexing
  cout << "A[1]: " << a[1] << endl;
  cout << "C[1]: " << c[2] << endl;
  //cout << "B[3]:(error) " << b[3] << endl;

  //Set vector values
  a.set(2,3,4);
  cout << "A set (2,3,4) : ";
  a.Print();

  //Max
  cout << "Max A: " << a.getMax() << endl;
  cout << "Max C: " << c.getMax() << endl;
  cout << "AbsMin D: " << d.getAbsMax() << endl;
  cout << "AbsMin E: " << e.getAbsMax() << endl;

  //Min
  cout << "Min A: " << a.getMin() << endl;
  cout << "Min C: " << c.getMin() << endl;
  cout << "AbsMax D: " << d.getAbsMin() << endl;
  cout << "AbsMax E: " << e.getAbsMin() << endl;

  //Length
  cout << "Length A: " << a.length() << endl;
  cout << "Length C: " << c.length() << endl;
  cout << "Length Squared D: " << d.lengthSquared() << endl;
  cout << "Length Squared E: " << e.lengthSquared() << endl;

  return 0;
}