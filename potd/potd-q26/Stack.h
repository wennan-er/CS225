#pragma once
#include <stack>
#include <cstddef>

class Stack {
public:
  int size() const;
  bool isEmpty() const;
  void push(int value);
  int pop();
  Stack();
private:
  std::stack<int> mystack;
};
