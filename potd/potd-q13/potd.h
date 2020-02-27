//
// Write a templated function `more` which takes in two variables of the same
// type and returns whichever variable is greater than (`>`) the other.
//
#include "Food.h"
#pragma once

template<typename T>
const T & more(const T &one, const T &two) {
    //T  result ;
    if (one > two){
      return one;
    }else{
      return two;
    }

}
