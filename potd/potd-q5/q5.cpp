// your code here
#include <iostream>
#include "Food.h"
#include "q5.h"

void increase_quantity(Food *p){
  int number = p->get_quantity()+1;
  p->set_quantity(number);
};
