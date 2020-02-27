#include "Friend.h"
#include <iostream>

std::vector<int> buildset(int size){
  std::vector<int> set;
  for (int i = 0; i < size; i++){
    set.push_back(-1);
  }
  return set;
}

void unionset(int x,int y, std::vector<int>& set){
  int root1 = findroot(x,set);
  int root2 = findroot(y,set);

  if (root1==root2) return;
  int size_x = size(x,set);
  int size_y = size(y,set);
  int newsize = size_x+size_y;

  if (size_x <= size_y){
   set[root1] = root2;
   set[root2] = -newsize;
  }
  else{
   set[root2] = root1;
   set[root1] = -newsize;
  }
}

int findroot(int x,std::vector<int>& set){
  if (set[x] < 0) return x;
  else{
    int root = findroot(set[x],set);
    set[x] = root;
    return root;
  }
}

int size(int x, std::vector<int>& set){
  int root = findroot(x,set);
    return -set[root];
}

void map(int x, std::vector<int>& parents, std::vector<int>& set) {
   for (int i = 0; i < int(parents.size());i++){
     if (parents[i] == 1) unionset(x,i,set);
   }
}

int findCircleNum(std::vector<std::vector<int>>& M) {
    int size = M.size();
    std::vector<int> set = buildset(size);

    for (int j = 0; j < size;j++){
      map(j,M[j],set);
    }
    int count = 0;
    for (int i = 0; i < size; i++){
      if (set[i] < 0) count++;
    }

    return count;
}
