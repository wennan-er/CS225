#ifndef _FRIEND_H
#define _FRIEND_H

#include <vector>

//static std::vector<int> set;
std::vector<int> buildset(int size);
void unionset(int x,int y,std::vector<int>& set);
int findroot(int x,std::vector<int>& set);
int size(int x,std::vector<int>& set);
void map(int x, std::vector<int>& parents,std::vector<int>& set);
//int find(int x, std::vector<int>& parents);
int findCircleNum(std::vector<std::vector<int>>& M);

#endif
