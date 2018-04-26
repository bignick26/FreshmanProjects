
#include <iostream>
#include <string>

using namespace std;

class Complex {
public:
  // Define your constructors here
  // Constructors
    Complex();
    Complex(double,double);
    Complex(const string&);
    ~Complex();

  // Define the other required member functions here
  // Member Functions
    void print(); //print value of complex number
    double getReal() const;
    double getImag() const;

  // Define your operator overloads here if using member function overloads
    Complex* operator+(const Complex& rhs);
    Complex* operator-(const Complex& rhs);
    Complex* operator*(const Complex& rhs);
    Complex* operator/(const Complex& rhs);


  // Define your Data Members here
  // Data Members
    double _real;
    double _imag;
};

// Define your operator overloads here if using non-member function
// operator overloads.







