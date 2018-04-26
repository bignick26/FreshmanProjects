//
// Created by brick on 9/29/16.
//

#ifndef NOTES_DOG_H
#define NOTES_DOG_H

#include <string>
#include <iostream>


class Dog {
public:
    Dog();
    Dog(int age);
    Dog(int age, std::string color);
    Dog(std::string color, std::string name);

    void Bark();
    void IntroduceSelf();

    void operator + (const Dog& rhs) const;

private:
    int _age;
    std::string _color;
    std::string _name;

};


#endif //NOTES_DOG_H
