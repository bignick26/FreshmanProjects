#include <iostream>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "complex.h"
#include "string-parse.h"

using namespace std;

int main()
{
  // Add any variables you might need here

  while(true)
  {
    string st = GetStringFromKeyboard(); // Get the  next input line
    // The types StringArray_t and CharArray_t are defined in string-parse.h
    // They are fixed length arrays of 2 elements.
    // The StringParse function returns an integer indicating how many
    // of the two are actually used.

    StringArray_t operands; // array of operands
    CharArray_t   delims;   // array of delimiters
    int count = StringParse(st, "+-*/", operands, delims);

    if (count == 0) break; // All done

    //cout << "Count: " << count << endl;

    // Debug code follows.  Remove this after testing
    /*
    for (int i = 0; i < count; ++i)
      {
        cout << "operands[" << i << "] = ";
        // Note use of the "empty()" method.  You will need this in your code
        // Also note we can index the strings with the indexing operator []
        // For example, st[0] would be the zeroth character of the string st
        if (operands[i].empty())
          {
            cout << "(Empty string)";
          }
        else
          {
            cout << operands[i] << endl;
          }
        cout << "delims[" << i << "] = ";
        if (delims[i] == 0)
          {
            cout << "(zero character)" << endl;
          }
        else
          {
            cout << delims[i] << endl;
          }
      }
     */
    // End of debug code.  Remove all the above debug

    // Now perform the calculation
    // YOUR CODE HERE

    Complex c1(operands[0]);
    Complex c2(operands[1]);
    Complex* ans;

    //Calculations:

    //if doing operation on previous term:
    if (operands[0].empty()) {
      c1 = *ans;
    }

    //Operations
    if (delims[0] == '+') {
      ans = c1+c2;
    }
    else if (delims[0] == '-') {
      ans = c1-c2;
    }
    else if (delims[0] == '*') {
      ans = c1*c2;
    }
    else if (delims[0] == '/') {
      ans = c1/c2;
    }
    else {
      ans = new Complex(c1.getReal(),c1.getImag());
    }

    /* OLD WAY (not operating overloading)
    if (delims[0] == '+') {
      newReal = r1 + r2;
      newImag = i1 + i2;
    } else if (delims[0] == '-') {
      newReal = r1 - r2;
      newImag = i1 - i2;
    } else if (delims[0] == '*') {
      newReal = (r1*r2)-(i1*i2);
      newImag = (r1*i2)+(i1*r2);
    } else if (delims[0] == '/') {
      double mag1 = sqrt((r1*r1)+(i1*i1));
      double mag2 = sqrt((r2*r2)+(i2*i2));
      double ang1 = atan2(i1,r1);
      double ang2 = atan2(i2,r2);
      double newMag = mag1/mag2;
      double newAng = ang1-ang2;
      newReal = newMag * cos(newAng);
      newImag = newMag * sin(newAng);
    } else {
      newReal = r1;
      newImag = i1;
    }
    */

    if(isinf(ans->getReal()) || isinf(ans->getImag())) {
      ans = new Complex(NAN,NAN);
    }

    ans->print();
    }
  return 0;  // Successful completion of main()
}

