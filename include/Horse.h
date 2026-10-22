#pragma once

#include "Animal.h"

class Horse : public Animal {
public:
  Horse(std::string name, int age, std::string breed);

  const std::string &getBreed() const;

  std::string sound() const override;

private:
  std::string breed_;
};
