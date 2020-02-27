// your code here
#include <iostream>
#include "Food.h"
#include "q5.h"

using namespace std;
int main(){

  Food *food = new Food();
  string food_name = food->get_name();
  cout << "You have " << food->get_quantity() <<" "<< food_name << "."<< endl;
  increase_quantity(food);
  cout << "You have " << food->get_quantity() << " "<<food_name << "."<<endl;

  delete food;
}
