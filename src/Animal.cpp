#include "Animal.h"

#include <iostream>

Animal::Animal(std::string name, int age) : name_(std::move(name)), age_(age) {}

const std::string &Animal::getName() const { return name_; }

int Animal::getAge() const { return age_; }

std::string Animal::sound() const { return name_ + " makes a sound."; }

void Animal::speak() const { std::cout << sound() << std::endl; }
