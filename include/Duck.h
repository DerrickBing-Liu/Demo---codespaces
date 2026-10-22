#pragma once

#include "Animal.h"

class Duck : public Animal {
public:
  Duck(std::string name, int age, std::string breed);

  const std::string &getBreed() const;

  std::string sound() const override;

private:
  std::string breed_;
};
