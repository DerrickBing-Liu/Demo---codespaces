#pragma once

#include "Machine.h"

class Robot : public Machine {
public:
  Robot(std::string name, int year, std::string model);

  const std::string &getModel() const;

  std::string operate() const override;
  void speak() const override;

private:
  std::string model_;
};
