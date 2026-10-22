#include "ProcessAnimalLargeMethod.h"

#include <iostream>
#include <memory>

#include "Animal.h"
#include "Dog.h"
#include "Duck.h"
#include "Horse.h"

// 一个函数执行了太多任务
void processAnimal(const std::string &animalType, bool isHungry,
                   bool isFriendly) {
  std::unique_ptr<Animal> animal;

  // 1. 创建动物对象
  if (animalType == "dog") {
    animal = std::make_unique<Dog>("Rex", 3, "Labrador");
  } else if (animalType == "duck") {
    animal = std::make_unique<Duck>("Waddles", 1, "Mallard");
  } else if (animalType == "horse") {
    animal = std::make_unique<Horse>("Thunder", 5, "Arabian");
  } else {
    std::cout << "Unknown animal." << '\n';
    return;
  }

  // 2. 获取动物叫声
  std::string sound = animal->sound();

  // 3. 生成基本信息
  std::string message = animalType + " says: " + sound;

  // 4. 根据饥饿状态生成消息
  if (isHungry) {
    message += " The animal is hungry.";

    // 5. 根据友好程度生成额外消息
    if (isFriendly) {
      message += " It is friendly.";
    } else {
      message += " It is not friendly.";
    }
  } else {
    message += " The animal is not hungry.";

    if (isFriendly) {
      message += " It is friendly.";
    } else {
      message += " It is not friendly.";
    }
  }

  // 6. 输出结果
  std::cout << "===== Animal Information =====" << '\n';
  std::cout << "Type: " << animalType << '\n';
  std::cout << "Sound: " << sound << '\n';
  std::cout << "Status: " << message << '\n';

  // 7. 根据状态执行不同动作
  if (isHungry) {
    std::cout << "Action: Feed the animal." << '\n';
  } else {
    std::cout << "Action: The animal does not need food." << '\n';
  }

  if (isFriendly) {
    std::cout << "Action: You can play with the animal." << '\n';
  } else {
    std::cout << "Action: Keep a safe distance." << '\n';
  }

  std::cout << "==============================" << '\n';
}
