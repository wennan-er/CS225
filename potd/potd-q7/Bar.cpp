// your code here
#include "Foo.h"
#include "Bar.h"
#include <string>

namespace potd{
  Bar::Bar(std::string name){

    f_ = new Foo(name);

  };

  //make a deep copy of the pointer f_
  Bar::Bar(const potd::Bar & other){
    copy(other);
    //using the copy ctor in Foo class to create a new Foo b

  };

  Bar::~Bar(){
    clear();
  };

  Bar &Bar::operator = (const potd::Bar & other){
    //using the operator = in Foo class
    //this->f_ Foo::= other.f_;
    //return *this;
    if (this!=&other){
      clear();
      copy(other);
    }
    return *this;
  };

  std::string Bar::get_name(){
    //using get name method in Foo class
    return f_->get_name();
  };

  void Bar::clear(){
    f_->~Foo();
  }

  void Bar::copy(const Bar& other){
    f_ = new Foo(*(other.f_));

  }
}
