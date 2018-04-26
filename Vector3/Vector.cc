//
// Created by Brian Swenson on 10/13/16.
//

#include "Vector.h"
#include <math.h>
#include <iostream>
using namespace std;

//do nothing
Vector::Vector() {

}

//set all values to xyz
Vector::Vector(float xyz) :
X(xyz), Y(xyz), Z(xyz)
{
  //this also works
  //X = xyz;
  //Y = xyz;
  //Z = xyz;
}

Vector::Vector(float x, float y, float z) :
X(x), Y(y), Z(z)
{
  //this also works
  //X = x;
  //Y = y;
  //Z = z;
}

//cross product
Vector Vector::operator^(const Vector& v) const {
  return Vector((Y*v.Z)-(Z*v.Y), -((X*v.Z)-(Z*v.X)), (X*v.Y)-(Y*v.X));
}

//return the cross product of a and b
Vector Vector::crossProduct(const Vector& a, const Vector& b) {
  return Vector((a.Y*b.Z)-(a.Z*b.Y), -((a.X*b.Z)-(a.Z*b.X)), (a.X*b.Y)-(a.Y*b.X));
}

//dot product
float Vector::operator|(const Vector& other) {
  return (X*other.X) + (Y*other.Y) + (Z*other.Z);
}

//return the dot product of a and b
float Vector::dotProduct(const Vector& a, const Vector& b) {
  return (a.X*b.X) + (a.Y*b.Y) + (a.Z*b.Z);
}

Vector Vector::operator+(const Vector& other) {
  return Vector(X + other.X, Y + other.Y, Z + other.Z);

  //or
  /*
   * Vector temp;
   * temp.X = X + other.X;
   * temp.Y = Y + other.Y;
   * temp.Z = Z + other.Z;
   * return temp;
   *
   */
}

//implement vector subtration
Vector Vector::operator-(const Vector& other) {
  return Vector(X - other.X, Y - other.Y, Z - other.Z);
}

//multiply x,y,z by scale
Vector Vector::operator*(float scale) {
  return Vector(X*scale,Y*scale,Z*scale);
}

//component multiplication
Vector Vector::operator*(const Vector &other) {
  return Vector(X*other.X, Y*other.Y, Z*other.Z);
}

//divide x,y,z by scale
Vector Vector::operator/(float scale) {
  return Vector(X/scale,Y/scale,Z/scale);
}

//component division
Vector Vector::operator/(const Vector& other) {
  return Vector(X/other.X, Y/other.Y, Z/other.Z);
}

//compare x's, y's and z's of vectors, return true if all equal, false if not
bool Vector::operator==(const Vector& v) const {
  return X==v.X && Y==v.Y && Z==v.Z;
}

//compare x's, y's and z's of vectors, return true if any are not equal, false if they are
bool Vector::operator!=(const Vector& v) const {
  return X!=v.X || Y!=v.Y || Z!=v.Z;
}

//short cut component add
Vector Vector::operator+=(const Vector& v) {
  return Vector(X+=v.X,Y+=v.Y,Z+=v.Z);
}

//short cut component subtract
Vector Vector::operator-=(const Vector& v) {
  return Vector(X-=v.X,Y-=v.Y,Z-=v.Z);
}

//short cut component scale (division)
Vector Vector::operator/=(float scale) {
  return Vector(X/=scale, Y/=scale, Z/=scale);
}

//short cut component scale (multiplication)
Vector Vector::operator*=(float scale) {
  return Vector(X*=scale, Y*=scale, Z*=scale);
}

//if index == 0, return x
//if index == 1, return y
//if index == 2, return z
//else throw error
float Vector::operator[](int index) {
  if (index ==0) {
    return X;
  }
  else if (index ==1) {
    return Y;
  }
  else if (index ==2) {
    return Z;
  }
  else {
    throw invalid_argument( "Received invalid index for vector" );
  }
}

void Vector::set(float x, float y, float z) {
  X = x;
  Y = y;
  Z = z;
}

//get the maximum value in x, y, and z
float Vector::getMax() const {
  float m = max(X,Y);
  return max(m,Z);
}

//get the maximum of the absolute values of x, y, z
float Vector::getAbsMax() const {
  double m = max(fabs(X),fabs(Y));
  return max(fabs(Z),m);
}

//get the smallest value in x, y, z
float Vector::getMin() const {
  float m = min(X,Y);
  return min(m,Z);
}


float Vector::getAbsMin() const {
  double m = min(fabs(X),fabs(Y));
  return min(fabs(Z),m);
}

//return the length of the vector
float Vector::length() const {
  return 3;
}

//return the length of the vector squared
float Vector::lengthSquared() const {
  return ((this->length())*(this->length()));
}

void Vector::Print() const {
  cout << X << ", " << Y << ", " << Z << endl;
}
