#include "Robot.h"

#include <iostream>

Robot::Robot(std::string name, int year, std::string model)
    : Machine(std::move(name), year), model_(std::move(model)) {}

const std::string &Robot::getModel() const { return model_; }

std::string Robot::operate() const {
  return name_ + " (" + model_ + ") says: Beep boop!";
}

void Robot::speak() const {
  std::cout << name_ << " (" << model_ << ") says: Hello, human!" << std::endl;
}
