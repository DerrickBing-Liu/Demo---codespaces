#include "Machine.h"

#include <iostream>

Machine::Machine(std::string name, int year)
    : name_(std::move(name)), year_(year) {}

const std::string &Machine::getName() const { return name_; }

int Machine::getYear() const { return year_; }

std::string Machine::operate() const { return name_ + " is operating."; }

void Machine::run() const { std::cout << operate() << std::endl; }

void Machine::speak() const {
  std::cout << name_ << " makes a mechanical noise." << std::endl;
}
