// Your code here
#include "potd.h"
#include <vector>

string getFortune(const string &s){
  int length = s.length();
  if (length % 5 == 1) {
    return "As you wish!";
  }
  if (length % 5 == 2) {
    return "Nec spe nec metu!";
  }
  if (length % 5 == 3) {
    return "Do, or do not. There is no try.";
  }
  if (length % 5 == 4) {
    return "This fortune intentionally left blank.";
  }
  if (length % 5 == 0) {
    return "Amor Fati!";
  }
  return "";
}
