
#include <iostream>
#include <string>

#include <math.h>

#include "complex.h"
#include "string-parse.h"

using namespace std;

// Implement your constructors here
// Constructors
Complex::Complex() {
  _real = 0;
  _imag = 0;
}

Complex::Complex(double real, double imag) {
  _real = real;
  _imag = imag;
}

Complex::Complex(const string& str) {
  //separate 3 or (2,1) or (2.15,3.5) or (-2.3,3) or (3>4)
  string nums;
  if (str[0] == '(') {
    nums = RemoveParens(str);
  }
  else {
    nums = str;
  }

  CharArray_t delims;
  StringArray_t numsArr;
  StringParse(nums,",>",numsArr, delims);
  double real = ToDouble(numsArr[0]);
  double imag = ToDouble(numsArr[1]);

  //debug
  //cout << real << endl;
  //cout << delims << endl;
  //cout << imag << endl;

  //set instance variables
  if (delims[0] == ',') {
    _real = real;
    _imag = imag;
  }
  else if (delims[0] == '>') {
    imag = (imag * M_PI)/180;
    _real = real * cos(imag);
    _imag = real * sin(imag);
  }
  else {
    _real = real;
    _imag = 0;
  }
}

Complex* Complex::operator+ (const Complex& rhs) {
  return new Complex((_real+rhs._real),(_imag+rhs._imag));
}

Complex* Complex::operator-(const Complex& rhs) {
  return new Complex((_real-rhs._real),(_imag-rhs._imag));
}

Complex* Complex::operator*(const Complex& rhs) {
  return new Complex(((_real*rhs._real)-(_imag*rhs._imag)),((_real*rhs._imag)+(_imag*rhs._real)));
}

Complex* Complex::operator/(const Complex& rhs) {
  double mag1 = sqrt((_real*_real)+(_imag*_imag));
  double mag2 = sqrt((rhs._real*rhs._real)+(rhs._imag*rhs._imag));
  double ang1 = atan2(_imag,_real);
  double ang2 = atan2(rhs._imag,rhs._real);
  double newMag = mag1/mag2;
  double newAng = ang1-ang2;
  return new Complex((newMag*cos(newAng)),(newMag*sin(newAng)));
}

void Complex::print() {
  if (_imag == 0) {
    cout << _real << endl;
  }
  else if (isnan(_imag) || isnan(_real)) {
    cout << "NaN" << endl;
  }
  else {
    cout << "(" << _real << "," << _imag << ")" << endl;
  }
  return;
}

double Complex::getReal() const {
  return _real;
}

double Complex::getImag() const {
  return _imag;
}

Complex::~Complex() {}
