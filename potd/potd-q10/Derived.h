#pragma once
#include "Base.h"

class Derived : public Base {
public:
  std::string foo();
  virtual std::string bar();
  ~Derived();
};
