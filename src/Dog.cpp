#include "Dog.h"

Dog::Dog(std::string name, int age, std::string breed)
    : Animal(std::move(name), age), breed_(std::move(breed)) {}

const std::string &Dog::getBreed() const { return breed_; }

std::string Dog::sound() const {
  return name_ + " (" + breed_ + ") says: Woof!";
}
