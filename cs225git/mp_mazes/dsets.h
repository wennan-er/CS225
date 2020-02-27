/* Your code here! */
#pragma once
#include <vector>

class DisjointSets{
public:
  void addelements(int num);
  int find(int elem);
  void setunion(int a, int b);
  int size(int elem);
  void printset();
private:
  std::vector<int> r; //r denotes relationship
  //std::vector<int> s; //s denotes value in set
};
