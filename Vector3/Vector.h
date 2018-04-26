//
// Created by Brian Swenson on 10/13/16.
//


class Vector {
public:
  float X;
  float Y;
  float Z;

  //do nothing
  Vector();

  //set all values to xyz
  Vector(float xyz);

  //set X, Y, Z by x, y, z respectively
  Vector(float x, float y, float z);

  //cross product
  Vector operator^(const Vector& v) const;

  //return the cross product of a and b
  static Vector crossProduct(const Vector& a, const Vector& b);

  //dot product
  float operator | (const Vector& other);

  //return the dot product of a and b
  static float dotProduct(const Vector& a, const Vector& b);

  //print x, y, z to std::cout
  void Print() const;

  //implement vector addition
  Vector operator+(const Vector& other);

  //implement vector subtration
  Vector operator-(const Vector& other);

  //multiply x,y,z by scale
  Vector operator*(float scale);

  //component multiplication
  Vector operator*(const Vector& other);

  //divide x,y,z by scale
  Vector operator/(float scale);

  //component division
  Vector operator/(const Vector& other);

  //compare x's, y's and z's of vectors, return true if all equal, false if not
  bool operator ==(const Vector& v) const;

  //compare x's, y's and z's of vectors, return false if any are not equal, true if they are
  bool operator !=(const Vector& v) const;

  //short cut component add
  Vector operator+=(const Vector& v);

  //short cut component subtract
  Vector operator-=(const Vector& v);

  //short cut component scale
  Vector operator/=(float scale);

  //short cut component scale
  Vector operator*=(float scale);

  //if index == 0, return x
  //if index == 1, return y
  //if index == 2, return z
  //else throw error
  float operator[](int index);

  void set(float x, float y, float z);

  //get the maximum value in x, y, and z
  float getMax() const;

  //get the maximum of the absolute values of x, y, z
  float getAbsMax() const;

  //get the smallest value in x, y, z
  float getMin() const;

  //get the smallest absolute value of x, y, z
  float getAbsMin() const;

  //return the length of the vector
  float length() const;

  //return the length of the vector squared
  float lengthSquared() const;
};


