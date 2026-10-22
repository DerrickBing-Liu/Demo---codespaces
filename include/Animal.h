#pragma once

#include <string>

class Animal {
public:
  Animal(std::string name, int age);
  virtual ~Animal() = default;

  const std::string &getName() const;
  int getAge() const;

  virtual std::string sound() const;
  void speak() const;

protected:
  std::string name_;
  int age_;
};
