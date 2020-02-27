// Animal.h
#pragma once
#include <string>

class Animal{
public:
  std::string getType();
  void setType(std::string type);
  std::string getFood();
  void setFood(std::string food);
  virtual std::string print();
  Animal();
  Animal(std::string type, std::string food);
private:
  std::string type_;
protected:
  std::string food_;

};
