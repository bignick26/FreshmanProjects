//
// Created by brick on 10/13/16.
//

#include "Vector.h"
#include <iostream>
using namespace std;

Vector::Vector() :
        X(0), Y(0), Z(0) {
}

//set all values to xyz
Vector::Vector(float xyz) :
        X(xyz), Y(xyz), Z(xyz) {
  //fast way to initialize;
}

Vector::Vector(float x, float y, float z) :
        X(x), Y(y), Z(z) {

}

void Vector::Print() const {
  cout << X << Y << Z << endl;
}

Vector& Vector::operator=(const Vector& other) {
  X = other.X;
  Y = other.Y;
  Z = other.Z;

  return *this;
}

Vector Vector::operator*(const Vector& other) {
  return Vector(X*other.X,Y*other.Y,Z*other.Z);
}