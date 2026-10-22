#pragma once

#include <string>

// 反面示例：一个函数承担了创建对象、拼接消息、打印输出等过多职责
void processAnimal(const std::string &animalType, bool isHungry,
                   bool isFriendly);
