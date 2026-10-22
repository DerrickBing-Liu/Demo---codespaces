#include "AnimalSoundNested.h"

#include "Animal.h"
#include "Dog.h"
#include "Duck.h"
#include "Horse.h"

// 根据 type 字符串创建具体的动物对象，并以 类型 -> 饥饿状态 -> 友好状态
// 三层嵌套 if-else 决定叫声
std::string animal_sound_nested(const std::string &type,
                                const std::string &name, int age,
                                const std::string &breed, bool isHungry,
                                bool isFriendly) {
  if (type == "Dog") {
    Dog dog(name, age, breed);
    if (isHungry) {
      if (isFriendly) {
        return dog.getName() + " is hungry but friendly, whines: Whine!";
      } else {
        return dog.getName() + " is hungry and grumpy, growls: Growl!";
      }
    } else {
      if (isFriendly) {
        return dog.sound();
      } else {
        return dog.getName() +
               " is full but unfriendly, barks a warning: Bark!";
      }
    }
  } else {
    if (type == "Duck") {
      Duck duck(name, age, breed);
      if (isHungry) {
        if (isFriendly) {
          return duck.getName() + " is hungry but friendly, chirps: Peep!";
        } else {
          return duck.getName() + " is hungry and irritable, hisses: Hiss!";
        }
      } else {
        if (isFriendly) {
          return duck.sound();
        } else {
          return duck.getName() + " is full but unfriendly, flaps away: Flap!";
        }
      }
    } else {
      if (type == "Horse") {
        Horse horse(name, age, breed);
        if (isHungry) {
          if (isFriendly) {
            return horse.getName() +
                   " is hungry but friendly, nickers: Nicker!";
          } else {
            return horse.getName() + " is hungry and restless, stomps: Stomp!";
          }
        } else {
          if (isFriendly) {
            return horse.sound();
          } else {
            return horse.getName() + " is full but unfriendly, snorts: Snort!";
          }
        }
      } else {
        Animal animal(name, age);
        if (isHungry) {
          if (isFriendly) {
            return animal.getName() + " is hungry but friendly, waits calmly.";
          } else {
            return animal.getName() + " is hungry and agitated, moves away.";
          }
        } else {
          if (isFriendly) {
            return animal.sound();
          } else {
            return animal.getName() +
                   " is full but unfriendly, keeps distance.";
          }
        }
      }
    }
  }
}
