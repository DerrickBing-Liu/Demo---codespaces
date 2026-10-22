#include "Horse.h"

Horse::Horse(std::string name, int age, std::string breed)
    : Animal(std::move(name), age), breed_(std::move(breed)) {}

const std::string &Horse::getBreed() const { return breed_; }

std::string Horse::sound() const {
  return name_ + " (" + breed_ + ") says: Neigh!";
}
