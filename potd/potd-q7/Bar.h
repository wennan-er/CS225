// your code here
#pragma once
#include "Foo.h"
#include <string>

namespace potd {
  class Bar{
  public:
    Bar(std::string name);
    Bar(const Bar & other);
    ~Bar();
    Bar & operator = (const Bar & other);
    std::string get_name();
  private:
    Foo * f_;
    void clear();
    void copy(const Bar& other);
};
  }
