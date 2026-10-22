#pragma once

#include <string>

// 根据 type 字符串，通过连续 if-else 分支创建具体的动物对象并返回其叫声
std::string animal_sound(const std::string &type, const std::string &name,
                         int age, const std::string &breed);
