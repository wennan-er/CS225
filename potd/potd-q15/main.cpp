#include "potd.h"
#include <iostream>
using namespace std;

int main() {
  // Test 1: An empty list
  Node * head = NULL;
  cout << stringList(head) << endl;

  // Test 2: A list with exactly one node
  //Node * node2 = NULL;
  //Node * head = Node(100,node2);


  cout << stringList(head) << endl;

  // Test 3: A list with more than one node

  return 0;
}
