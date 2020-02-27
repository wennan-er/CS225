#include <iterator>
#include <cmath>

#include <list>
#include <queue>
#include <stack>
#include <vector>

#include "../cs225/PNG.h"
#include "../Point.h"

#include "ImageTraversal.h"
#include "BFS.h"

using namespace cs225;

/**
 * Initializes a breadth-first ImageTraversal on a given `png` image,
 * starting at `start`, and with a given `tolerance`.
 * @param png The image this BFS is going to traverse
 * @param start The start point of this BFS
 * @param tolerance If the current point is too different (difference larger than tolerance) with the start point,
 * it will not be included in this BFS
 */
BFS::BFS(const PNG & png, const Point & start, double tolerance) {
  /** @todo [Part 1] */
  queuetmp.push(start);

  toler = tolerance;
  image = png;
  Pixelstart=png.getPixel(start.x,start.y);
  visited.resize(image.width());
  for (unsigned i = 0; i < visited.size(); i++) {
    visited[i].resize(image.height());
      for (unsigned j = 0; j < visited[i].size(); j++) {
        visited[i][j] = false;
      }
  }
}

/**
 * Returns an iterator for the traversal starting at the first point.
 */
ImageTraversal::Iterator BFS::begin() {
  /** @todo [Part 1] */
  return ImageTraversal::Iterator(this);
}

/**
 * Returns an iterator for the traversal one past the end of the traversal.
 */
ImageTraversal::Iterator BFS::end() {
  /** @todo [Part 1] */
  return ImageTraversal::Iterator();
}

/**
 * Adds a Point for the traversal to visit at some point in the future.
 */
void BFS::add(const Point & point) {
  /** @todo [Part 1] */

    if (canbeadded(point)){
      if (!isinvisited(point)){
         queuetmp.push(point);
       }
    }
  }


/**
 * Removes and returns the current Point in the traversal.
 */
Point BFS::pop() {
  /** @todo [Part 1] */
  if (queuetmp.empty()){
    return Point(-1,-1);
  }
  Point curr = queuetmp.front();
  if (!isinvisited(curr)){
      visited[curr.x][curr.y] = true;
  }
  queuetmp.pop();
  return curr;
}


/**
 * Returns the current Point in the traversal.
 */
Point BFS::peek() const {
  /** @todo [Part 1] */
  if (empty()){
    return Point(-1, -1);
  }
  return queuetmp.front();
}

/**
 * Returns true if the traversal is empty.
 */
bool BFS::empty() const {
  /** @todo [Part 1] */
  if (queuetmp.empty()){
    return true;
  }
  return false;
}
