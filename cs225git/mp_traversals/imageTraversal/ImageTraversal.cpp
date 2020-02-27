#include <cmath>
#include <iterator>
#include <iostream>

#include "../cs225/HSLAPixel.h"
#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"

/**
 * Calculates a metric for the difference between two pixels, used to
 * calculate if a pixel is within a tolerance.
 *
 * @param p1 First pixel
 * @param p2 Second pixel
 * @return the difference between two HSLAPixels
 */
double ImageTraversal::calculateDelta(const HSLAPixel & p1, const HSLAPixel & p2) {
  double h = fabs(p1.h - p2.h);
  double s = p1.s - p2.s;
  double l = p1.l - p2.l;

  // Handle the case where we found the bigger angle between two hues:
  if (h > 180) { h = 360 - h; }
  h /= 360;

  return sqrt( (h*h) + (s*s) + (l*l) );
}

/**
 * Default iterator constructor.
 */
ImageTraversal::Iterator::Iterator() {
  /** @todo [Part 1] */
  traversal = NULL;
  current = Point(-1,-1);
}

ImageTraversal::Iterator::Iterator(ImageTraversal *traversal):
traversal(traversal)
{
  current = traversal->peek();
}
/**
 * Iterator increment opreator.
 *
 * Advances the traversal of the image.
 */
ImageTraversal::Iterator & ImageTraversal::Iterator::operator++() {
  /** @todo [Part 1] */

  if (!traversal->empty()){
     current = traversal->pop();
     traversal->addto(current);
     current = traversal->peek();
    while (!traversal->empty()&&traversal->isinvisited(current)){
      traversal->pop();
      current = traversal->peek();
    }
}
  return *this;
}

/**
 * Iterator accessor opreator.
 *
 * Accesses the current Point in the ImageTraversal.
 */
Point ImageTraversal::Iterator::operator*() {
  /** @todo [Part 1] */
  return current;
}

/**
 * Iterator inequality operator.
 *
 * Determines if two iterators are not equal.
 */
bool ImageTraversal::Iterator::operator!=(const ImageTraversal::Iterator &other) {
  /** @todo [Part 1] */
  bool thisEmpty = false;
  bool otherEmpty = false;

  if (traversal == NULL) { thisEmpty = true; }
  if (other.traversal == NULL) { otherEmpty = true; }

  if (!thisEmpty)  { thisEmpty = traversal->empty(); }
  if (!otherEmpty) { otherEmpty = other.traversal->empty(); }

  if (thisEmpty && otherEmpty) return false; // both empty then the traversals are equal, return true
   else if ((!thisEmpty)&&(!otherEmpty)) return (traversal != other.traversal); //both not empty then compare the traversals
  else return true; // one is empty while the other is not, return true
  /*
  if (current==other.current){
    return true;
  }
  return false;
  */
}

void ImageTraversal::addto(Point point){
  Point right(point.x+1,point.y);
  Point below(point.x,point.y+1);
  Point left(point.x-1,point.y);
  Point above(point.x,point.y-1);
  add(right);
  add(below);
  add(left);
  add(above);

}




bool ImageTraversal::isinvisited(Point point){
  if (isinboundary(point)){
  if (visited[point.x][point.y] == true){
    return true;
  }else{
    return false;
  }
}
return false;
}

bool ImageTraversal::canbeadded(Point point){
  // std::cout << point.x <<","<< point.y << " " << isinboundary(point)<<std::endl;
  if (!isinboundary(point)){
    return false;
  }
  HSLAPixel &Pixeltmp = image.getPixel(point.x,point.y);
  double value = calculateDelta(Pixelstart,Pixeltmp);
  if (value <= toler){
    return true;
  }
  return false;
}

bool ImageTraversal::isinboundary(Point point){
  if (int(point.x) < 0){
    return false;
  }
  if (int(point.y) < 0){
    return false;
  }
  if (point.x >= image.width()){
    return false;
  }
  if (point.y >= image.height()){
    return false;
  }
  return true;
}
