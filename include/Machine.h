#pragma once

#include <string>

class Machine {
public:
  Machine(std::string name, int year);
  virtual ~Machine() = default;

  const std::string &getName() const;
  int getYear() const;

  virtual std::string operate() const;
  void run() const;
  virtual void speak() const;

protected:
  std::string name_;
  int year_;
};
