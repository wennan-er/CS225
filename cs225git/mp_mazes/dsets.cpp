/* Your code here! */
#include <iostream>
#include "dsets.h"
void DisjointSets::printset(){
  for (auto it=r.begin(); it!=r.end(); it++){
    std::cout << find(*it) << std::endl;
  }
}
void DisjointSets::addelements(int num){
  for (int i = num; i > 0; i--){
    r.push_back(-1);
  }
}
//return the index of the root of the up-tree in which the parameter element resides
int DisjointSets::find(int elem){
  if (r[elem] < 0) return elem;
  else{
    int root = find(r[elem]);
    r[elem] = root;
    return root;
  }
}
/*
a	Index of the first element to union
b	Index of the second element to union
This function should be implemented as union-by-size.
*/
void DisjointSets::setunion(int a, int b){
  int root1 = find(a); //index of root a belongs to
  int root2 = find(b);
  if (root1==root2) return;

  if (root1 < root2){
    r[root1] = r[root1]+r[root2];
    r[root2] = root1;
  }
  else{
    r[root2] = r[root1]+r[root2];
    r[root1] = root2;
  }

}
int DisjointSets::size(int elem){
    int root = find(elem);
    return -r[root];
}
