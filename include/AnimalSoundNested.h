#pragma once

#include <string>

// 根据 type 字符串创建具体的动物对象，并以 类型 -> 饥饿状态 -> 友好状态
// 三层嵌套 if-else 决定叫声
std::string animal_sound_nested(const std::string &type,
                                const std::string &name, int age,
                                const std::string &breed, bool isHungry,
                                bool isFriendly);
