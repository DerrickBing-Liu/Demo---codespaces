#include <iostream>
#include <memory>

#include "Animal.h"
#include "AnimalCreation.h"
#include "AnimalSoundIfElseChain.h"
#include "AnimalSoundNested.h"
#include "Dog.h"
#include "Duck.h"
#include "Horse.h"
#include "ProcessAnimalLargeMethod.h"
#include "Robot.h"
#include "main.h"

int main() {
  Robot robot("Robo", 1, "T-800");
  robot.speak();

  Animal animal("Generic Animal1", 3);
  animal.speak();

  Dog dog("Buddy", 2, "Golden Retriever");
  dog.speak();

  Horse horse("Thunder", 5, "Arabian");
  horse.speak();

  Duck duck("Waddles", 1, "Mallard");
  duck.speak();

  std::unique_ptr<Animal> polymorphicAnimal =
      std::make_unique<Dog>("Rex", 4, "German Shepherd");
  polymorphicAnimal->speak();

  PrintAnimalSounds();

  PrintNestedAnimalSounds();

  ProcessAnimalSounds();

  AnimalCreation();

  return 0;
}

void ProcessAnimalSounds() {
  processAnimal("dog", true, true);
  processAnimal("duck", false, false);
  processAnimal("unknown", true, false);
}

void PrintNestedAnimalSounds() {
  std::cout << animal_sound_nested("Dog", "Puppy", 0, "Beagle", true, true)
            << std::endl;
  std::cout << animal_sound_nested("Duck", "Waddles", 1, "Mallard", false,
                                   false)
            << std::endl;
  std::cout << animal_sound_nested("Horse", "Foal", 0, "Arabian", true, false)
            << std::endl;
  std::cout << animal_sound_nested("Unknown", "Generic Animal", 3, "", false,
                                   true)
            << std::endl;
}

void PrintAnimalSounds() {
  std::cout << animal_sound("Dog", "Buddy", 2, "Golden Retriever") << std::endl;
  std::cout << animal_sound("Duck", "Waddles", 1, "Mallard") << std::endl;
  std::cout << animal_sound("Horse", "Thunder", 5, "Arabian") << std::endl;
  std::cout << animal_sound("Unknown", "Generic Animal", 3, "") << std::endl;
}
