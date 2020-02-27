/* Your code here! */
#pragma once
#include <vector>
#include "dsets.h"
#include "cs225/PNG.h"
#include "dsets.h"
using namespace std;
using namespace cs225;

class SquareMaze{
public:
  /*
  struct Cell{
    bool right;
    bool down;
    int distance;
    Cell():right(true),down(true),distance(1){};
  };
  */
  SquareMaze();
  void makeMaze(int width, int height);
  bool canTravel(int x, int y, int dir) const;
  void setWall(int x, int y, int dir, bool exists);
  vector<int> solveMaze();
  PNG* drawMaze() const;
  PNG* drawMazeWithSolution();

  void RemoveRight(int x, int y);
  void RemoveDown(int x, int y);
  PNG* drawCreativeMaze();
private:
  DisjointSets set;
  //vector<vector<Cell>> maze;
  vector<bool> rightWalls;
  vector<bool> downWalls;
  int width_;
  int height_;
  int end;
};
