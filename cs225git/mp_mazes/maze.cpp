/* Your code here! */

#include "maze.h"
#include <utility>
#include <sys/time.h>
#include <queue>
using namespace std;

void SquareMaze::RemoveRight(int x, int y){
  if (x == width_ -1 ) return ;
  //Cell c_left = maze[y][x];
  //Cell c_right = maze[y][x+1];
  if (set.find(y * width_ + x) == set.find(y * width_ + x + 1)) return;
  else {
    set.setunion(y * width_ + x,y * width_ + x + 1);
    //c_left.right = false;
    //c_right.distance += c_left.distance;
    rightWalls[y * width_ + x] = false;
    //cout << "right"<<"-"<<x<<":"<<y<< endl;
  }
}
void SquareMaze::RemoveDown(int x, int y){
  if (y == height_ -1) return ;
  //Cell c_up = maze[y][x];
  //Cell c_down = maze[y+1][x];
  if (set.find(y * width_ + x) == set.find(y * width_ + x + width_)) return;
  else {
    set.setunion(y * width_ + x,y * width_ + x + width_);
    //c_up.down = false;
    //c_down.distance += c_up.distance;
    downWalls[y * width_ + x] = false;
    //cout << "down"<<"-"<<x<<":"<<y<< endl;
  }
}


SquareMaze::SquareMaze(){

}
void SquareMaze::makeMaze(int width, int height){
  width_ = width;
  height_ = height;
  int mazesize = width * height;
  set.addelements(mazesize);
 //initialize
  for(int i = 0; i < mazesize; i++){
    rightWalls.push_back(true);
    downWalls.push_back(true);
  }

  struct timeval tv;
 gettimeofday(&tv,NULL);
 srand(tv.tv_usec);
//  maze = vector<vector<Cell>> (height,vector<Cell>(width));
 //union the set
   while(set.size(0) < mazesize){
      int x = rand() % width_;
      int y = rand() % height_;
      //cout << x <<":"<< y<< endl;
      int random = rand() % 2;
      if (random == 0) RemoveRight(x,y);
      else RemoveDown(x,y);
    }

  }
/*
dir = 0 represents a rightward step (+1 to the x coordinate)
dir = 1 represents a downward step (+1 to the y coordinate)
dir = 2 represents a leftward step (-1 to the x coordinate)
dir = 3 represents an upward step (-1 to the y coordinate)
*/
bool SquareMaze::canTravel(int x, int y, int dir)const{
  if (dir == 0){
    return rightWalls[y * width_ + x] == false;
  }
 if (dir == 1){
  return downWalls[y * width_ + x] == false;
 }
  if (dir == 2 && x!= 0) {
    return rightWalls[y * width_ + x - 1] == false;
  }
  if (dir == 3 && y!= 0){
     return downWalls[y * width_ + x - width_] == false;
   }
  else{
    return false;
  }
}
void SquareMaze::setWall(int x, int y, int dir, bool exists){
  if (dir == 0 ) {
    rightWalls[y * width_ + x] = exists;
  }
 else if (dir == 1){
    downWalls[y * width_ + x] = exists;
}
}
vector<int> SquareMaze::solveMaze(){
  //find the teminal :[height_-1][index]
  int x,y,cur;
  vector<int> prev(width_ * height_,-1);
  queue<int> q;
  vector<int> solution;
  vector<int> distance(width_ * height_,0);
  q.push(0);
  prev.push_back(0);
  //solve the maze
  while(!q.empty()){
    cur = q.front();
    x = cur % width_;
    y = cur / width_;
    q.pop();
    //0 for right
    if(canTravel(x, y, 0)){
        if(prev[cur + 1] == -1){
          q.push(cur + 1);
          prev[cur + 1] = cur;
          distance[cur + 1] = distance[cur] + 1;
        }
      }
    //1 for down
    if(canTravel(x, y, 1)){
        if(prev[cur + width_] == -1){
          q.push(cur + width_);
          prev[cur + width_] = cur;
          distance[cur + width_] = distance[cur] + 1;
        }
      }
    //2 for left
    if(canTravel(x, y, 2)){
        if(prev[cur - 1] == -1){
          q.push(cur - 1);
          prev[cur - 1] = cur;
          distance[cur - 1] = distance[cur] + 1;
        }
      }
    //3 for up
    if(canTravel(x, y, 3)){
        if(prev[cur - width_] == -1){
          q.push(cur - width_);
          prev[cur - width_] = cur;
          distance[cur - width_] = distance[cur] + 1;
        }
      }
    }
    //find the longest path
    int longest_path = width_ * (height_ - 1);
    for(int i = 0; i < width_; i++){
      if(distance[width_ * (height_ - 1) + i] > distance[longest_path]){
        longest_path = width_ * (height_ - 1) + i;
      }
    }
    end = longest_path;
    cur = longest_path;
    //from end to start, back push into solution
    while(cur != 0){
      if(prev[cur] == cur - 1){
        solution.push_back(0);
      }
      if(prev[cur] == cur - width_){
        solution.push_back(1);
      }
      if(prev[cur] == cur + 1){
        solution.push_back(2);
      }
      if(prev[cur] == cur + width_){
        solution.push_back(3);
      }
      cur = prev[cur];
    }
    reverse(solution.begin(), solution.end());

  return solution;

}
PNG * SquareMaze::drawMaze()const{
   int png_width = width_ * 10 + 1;
   int png_height = height_ * 10 + 1;
   PNG* png = new PNG(png_width,png_height);
   // draw the outline
   for(int y = 0; y < png_height; y++){
    HSLAPixel& p = png->getPixel(0, y);
    p.l = 0;
  }
  for(int x = 10; x < png_width; x++){
    HSLAPixel& p = png->getPixel(x, 0);
    p.l = 0;
  }
  //drawMaze
  for (int x = 0; x < width_; x++){
    for (int y = 0; y < height_; y++){
      if (rightWalls[y * width_ + x]){
        for(int i = 0; i <= 10; i++){
          HSLAPixel& p = png->getPixel((x + 1) * 10, y * 10 + i);
          p.l = 0;
        }
      }
      if (downWalls[y * width_ + x]){
        for(int i = 0; i <= 10; i++){
          HSLAPixel& p = png->getPixel(x  * 10 + i, (y+1) * 10 );
          p.l = 0;
        }
      }
    }
  }
  //
   return png;
}
PNG * SquareMaze::drawMazeWithSolution(){
  PNG* png = drawMaze();
  vector<int> solution = solveMaze();
  int x = 5;
  int y = 5;

  int end_x = end % width_;
  int end_y = end / height_;
  for (int i = 1; i <= 9; i++){
    HSLAPixel& p = png->getPixel(end_x * 10 + i, (end_y + 1) * 10);
     p.l = 1;
  }
  for (int i = 0; i < int(solution.size()); i++){
    if (solution[i] == 0){
      for (int j = 0; j <= 10; j++){
        HSLAPixel& p = png->getPixel(x+j,y);
        p.h = 0;
        p.s = 1;
        p.l = 0.5;
        p.a = 1;
      }
      x+=10;

    }
    else if (solution[i] == 1){
      for (int j = 0; j <= 10; j++){
        HSLAPixel& p = png->getPixel(x,y+j);
        p.h = 0;
        p.s = 1;
        p.l = 0.5;
        p.a = 1;
      }
      y+=10;
    }
    else if (solution[i] == 2){
      for (int j = 0; j <= 10; j++){
        HSLAPixel& p = png->getPixel(x-j,y);
        p.h = 0;
        p.s = 1;
        p.l = 0.5;
        p.a = 1;
      }
      x-=10;
    }
    else if (solution[i] == 3){
      for (int j = 0; j <= 10; j++){
        HSLAPixel& p = png->getPixel(x,y-j);
        p.h = 0;
        p.s = 1;
        p.l = 0.5;
        p.a = 1;
      }
      y-=10;
    }
  }
  return png;
}

PNG* SquareMaze::drawCreativeMaze(){
  int png_width = width_ * 10 + 1;
  int png_height = height_ * 10 + 1;
  PNG* png = new PNG(png_width,png_height);

  for(int y = 0; y < png_height ; y++){
    HSLAPixel& p = png->getPixel(0, y);
    p.l = 0;
  }

  for(int x = 10; x < png_width/3; x++){
    HSLAPixel& p = png->getPixel(x, 0);
    p.l = 0;
  }

  //drawMaze
  for(int y = 0; y < height_; y++){
    for(int x = 0; x < int(png_width/3); x++){
      if(rightWalls[y * width_ + x]){

            for(int i = 0; i <= 10; i++){
              HSLAPixel& p = png->getPixel((x + 1) * 10, y * 10 + i);
              p.h = 200;
              p.s = 1;
              p.l = 0.5;
              p.a = 1;
            }
          }
        if(downWalls[y * width_ + x]){
            for(int i = 0; i <= 10; i++){
              HSLAPixel& p = png->getPixel(x * 10 + i, (y + 1) * 10);
              p.h = 150;
              p.s = 1;
              p.l = 0.5;
              p.a = 1;
              }
            }
          }
    for(int x = 2*int(png_width/3); x < png_width; x++){
      if(rightWalls[y * width_ + x]){

            for(int i = 0; i <= 10; i++){
              HSLAPixel& p = png->getPixel((x + 1) * 10, y * 10 + i);
              p.h = 10;
              p.s = 1;
              p.l = 0.5;
              p.a = 1;
            }
          }
        if(downWalls[y * width_ + x]){
            for(int i = 0; i <= 10; i++){
              HSLAPixel& p = png->getPixel(x * 10 + i, (y + 1) * 10);
              p.h = 60;
              p.s = 1;
              p.l = 0.5;
              p.a = 1;
              }
            }
    }
  }
  //draw middle
  for(int x = int(width_ / 3); x < 2 * int(width_ / 3); x++){
    for(int y = 2*int(height_ / 5); y < 3 * int(height_ / 5); y++){
      if(rightWalls[y * width_ + x]){

            for(int i = 0; i <= 10; i++){
              HSLAPixel& p = png->getPixel((x + 1) * 10, y * 10 + i);
              p.h = 240;
              p.s = 1;
              p.l = 0.5;
              p.a = 1;
            }
          }
        if(downWalls[y * width_ + x]){
            for(int i = 0; i <= 10; i++){
              HSLAPixel& p = png->getPixel(x * 10 + i, (y + 1) * 10);
              p.h = 240;
              p.s = 1;
              p.l = 0.5;
              p.a = 1;
              }
            }
    }
  }
  return png;
}
