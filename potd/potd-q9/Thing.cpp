// Your code here!
#include <string>
#include "Thing.h"
namespace potd{
  Thing::Thing(int number){
    props_max_ = number;
    props_ct_ = 0;
    properties_ = new std::string[props_max_];
    values_ = new std::string[props_max_];
  };

  Thing::Thing(const Thing &other){
    _copy(other);

  };

  Thing& Thing :: operator=(const Thing &other){
    if (this!= &other){
      _destroy();
      _copy(other);
    }
    return *this;

  };
  Thing::~Thing(){
    _destroy();

  };

  int Thing::set_property(std::string prop,std::string val){
    bool flag = false;
    if (props_ct_ < props_max_){
      for (int i=0; i <props_ct_+1;i++){
        if (properties_[i] == prop){
          values_[i] = val;
          flag = true;
          return i;
        }
      }
      if (flag == false){
        properties_[props_ct_] = prop;
        values_[props_ct_] =  val;
        props_ct_++;
        return props_ct_-1;
      }
    }
    for (int i=0; i <props_ct_+1;i++){
      if (properties_[i] == prop){
        values_[i] = val;
        return i;
      }
  }
  return -1;
}

  std::string Thing::get_property(std::string prop){
    for (int i=0; i <props_max_;i++){
      if (properties_[i] == prop){
        return values_[i];
      }
    }
    return "";
  }


  void Thing::_copy(const Thing &other){
    properties_ = new std::string[other.props_max_];
    values_ = new std::string[other.props_max_];

    props_ct_ = other.props_ct_;
    props_max_ = other.props_max_;
    for (int i=0; i<other.props_max_;i++){
      properties_[i] = other.properties_[i];
      values_[i] = other.values_[i];
    }

  };
  void Thing::_destroy(){
    delete [] properties_;
    delete [] values_;

  };
}
