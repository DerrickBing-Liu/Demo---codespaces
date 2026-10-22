#include "Duck.h"

Duck::Duck(std::string name, int age, std::string breed)
    : Animal(std::move(name), age), breed_(std::move(breed)) {}

const std::string &Duck::getBreed() const { return breed_; }

std::string Duck::sound() const {
  return name_ + " (" + breed_ + ") says: Quack!";
}
