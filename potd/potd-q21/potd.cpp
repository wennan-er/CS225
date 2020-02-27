#include "potd.h"
using namespace std;
// Your code here!
double sum(vector<double>::iterator start, vector<double>::iterator end){
  double result = 0;
  for (auto i = start; i!= end; ++i){
    result += *i;

  }
  return result;

}

/** Returns an iterator that points to the element with the largest value between start and end. */
vector<double>::iterator max_iter(vector<double>::iterator start, vector<double>::iterator end){
  vector<double>::iterator max = start;
  for (auto i = start; i!= end; ++i){
    if (*i > *max){
      max = i;
    }
  }
  return max;
}

/** Sort, in descending order, part of an array between start to end.
	Hint: use max_iter.
*/
void sort_vector(vector<double>::iterator start, vector<double>::iterator end){
  if (start!=end){
   vector<double>::iterator first = max_iter(start,end);
   double tmp = *start;
   *start = *first;
   *first = tmp;
   sort_vector(start+1,end);
 }
}
