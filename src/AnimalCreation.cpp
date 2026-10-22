#include "AnimalCreation.h"

#include <iostream>
#include <memory>
#include <string>

#include "Animal.h"
#include "Dog.h"
#include "Duck.h"
#include "Horse.h"

void AnimalCreation() {
  std::string animalType = "dog";
  std::unique_ptr<Animal> animal;

  if (animalType == "dog") {
    animal = std::make_unique<Dog>("Buddy", 2, "Golden Retriever");
  } else if (animalType == "duck") {
    animal = std::make_unique<Duck>("Waddles", 1, "Mallard");
  } else if (animalType == "horse") {
    animal = std::make_unique<Horse>("Thunder", 5, "Arabian");
  }

  if (animal) {
    animal->speak();
  } else {
    std::cout << "Unknown animal\n";
  }
}