//
// Created by brick on 9/29/16.
//

#include "Dog.h"

Dog::Dog() {
    _age = 0;
    _color = "yellow";
    _name = "bill";
}

Dog::Dog(int age){
    _age = age;
    _color = "yellow";
    _name = "bill";
}

Dog::Dog(int age, std::string color){
    _age = age;
    _color = color;
    _name = "bill";
}

Dog::Dog(std::string color, std::string name){
    _age = 17;
    _color = color;
    _name = name;
}

void Dog::Bark(){
    std::cout << "woof!" << std::endl;

}
void Dog::IntroduceSelf(){
    std::cout << "Hello I am " << _name << std::endl;

}

void Dog::operator + (const Dog& rhs) const{
    std::cout << "Hi we are two dogs " << _name << " and " << rhs._name << std::endl;
}