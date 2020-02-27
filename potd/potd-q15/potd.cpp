#include "potd.h"
#include <iostream>

using namespace std;
int count = -1;
string stringList(Node *head) {
    // your code here!

    if (head == NULL){
      return "Empty list";
    }
    if (head->next_ == NULL){
      count++;
      return "Node " + to_string(count) + ": "+ to_string(head->data_);
    }

    else{
      count++;
      return "Node " + to_string(count) + ": "+ to_string(head->data_)+" -> " + stringList(head->next_)
      ;
    }

}
