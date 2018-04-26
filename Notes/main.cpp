#include <iostream>
#include <string>
#include <cstddef>
#include <math.h>
#include "Dog.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;
    cout << M_PI << endl;

    string myString = "3          ,            15";
    string myString2 = "2 > 5";
    size_t pos = myString.find_first_of(",>");
    size_t pos2 = myString2.find_first_of(",>");

    std::cout << pos << std::endl;
    std::cout << pos2 << std::endl;

    Dog barney(5, "blue");
    Dog fred("blue","fred");

    barney + fred;
    barney.Bark();
    barney.IntroduceSelf();

    return 0;
}