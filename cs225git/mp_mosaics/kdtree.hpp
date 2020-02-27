/**
 * @file kdtree.cpp
 * Implementation of KDTree class.
 */

#include <utility>
#include <algorithm>

using namespace std;

template <int Dim>
bool KDTree<Dim>::smallerDimVal(const Point<Dim>& first,
                                const Point<Dim>& second, int curDim) const
{
    /**
     * @todo Implement this function!
     */
     if (curDim < 0 || curDim >= Dim) return false;
     if (first[curDim]== second[curDim]) return first < second;
     return (first[curDim]< second[curDim]);

}

template <int Dim>
int distance(const Point<Dim>& target,
                                const Point<Dim>& potential)
{
   int sum = 0;
   for(int i = 0; i < Dim; i++){
     sum+= pow(target[i]- potential[i],2);
   }
   return sum;
}

template <int Dim>
bool KDTree<Dim>::shouldReplace(const Point<Dim>& target,
                                const Point<Dim>& currentBest,
                                const Point<Dim>& potential) const
{
    /**
     * @todo Implement this function!
     */
     int d1 = distance(target, potential);
     int d2 = distance(target, currentBest);
     if (d1==d2) return potential < currentBest;
     return (d1<d2);

}
template <int Dim>
void KDTree<Dim>::swap(vector<Point<Dim>>& list,int first, int second){
	Point<Dim> temp = list[first];
	list[first] = list[second];
	list[second] = temp;
}
//partition the list- choose pivot the first ele in the list

template <int Dim>
int KDTree<Dim>::partition(vector<Point<Dim>> &list,int dim, int left, int right){
	Point<Dim> pivot = list[left];
	int i = left+1;
	int j = left+1;

	for( ; j<=right; j++){
		if( smallerDimVal(list[j], pivot,dim)){
			swap(list, i, j);
			i++;
		}
	}
	swap(list, i-1, left);
	return i-1;
}



//return the k-th smallest element in the list

template <int Dim>
Point<Dim>& KDTree<Dim>::quickselect(vector<Point<Dim>> &list,int dim,int left,int right,int k)
{
   if (left == right){
     return list[left];
   }
   int split = partition(list, dim, left, right);

   int length = split - left + 1;
   if (length == k){
     return list[split];
   }
   else if (k < length) {
     return quickselect(list,dim, left, split -1, k);
   }
   else{
     return quickselect(list, dim, split+1, right, k-length);
   }
}

template <int Dim>
typename KDTree<Dim>::KDTreeNode* KDTree<Dim>::buildTree(vector<Point<Dim>> &list,int dim,int left, int right)
{
  if (left >right ) return NULL;

  if (left == right){
    KDTreeNode* subroot = new KDTreeNode(list[left]);
    return subroot;
  }

  int middle = (right+left)/2;
  int index = ceil((right - left+1)/2.0);

  KDTreeNode* subroot = new KDTreeNode(quickselect(list,dim%Dim,left,right,index));
  dim++;
  subroot->left = buildTree(list,dim%Dim,left,middle-1);
  subroot->right = buildTree(list,dim%Dim,middle+1,right);
  return subroot;
}


template <int Dim>
KDTree<Dim>::KDTree(const vector<Point<Dim>>& newPoints)
{
    /**
     * @todo Implement this function!
     */
     vector<Point<Dim>> list = newPoints;
     size = int(list.size());
     root = buildTree(list,0,0,size-1);
}

template <int Dim>
KDTree<Dim>::KDTree(const KDTree<Dim>& other) {
  /**
   * @todo Implement this function!
   */
   root = copy(other.root);
   size = other.size;
}

template <int Dim>
const KDTree<Dim>& KDTree<Dim>::operator=(const KDTree<Dim>& rhs) {
  /**
   * @todo Implement this function!
   */
   if (this!=rhs){
     destroy(root);
     root = copy(rhs.root);
     size = rhs.size;
   }
  return *this;
}

template <int Dim>
KDTree<Dim>::~KDTree() {
  /**
   * @todo Implement this function!
   */
   destroy(root);
   size = 0;
}
/*
template <int Dim>
Point<Dim> KDTree<Dim>::find_helper(KDTreeNode *subroot,Point<Dim>& query,int dim) const
{
  if (subroot->left == NULL && subroot->right == NULL)
        return subroot->point;
  //root is small
  Point<Dim> potential = subroot->point;
  Point<Dim> currentBest;
  Point<Dim> potential2;
  //go to left subtree
  if (smallerDimVal(subroot->point,query,dim%Dim)){
    if (subroot->left == NULL){

      currentBest = potential;
    }else{
       currentBest = find_helper(subroot->left,query,(dim+1)%Dim);
      //if potential is smaller
      if (shouldReplace(query,currentBest,potential)){
        currentBest = potential;
      }
    }
   //check if go to right subtree
   if (subroot->right!= NULL &&
     smallerDimVal(subroot->right->point,currentBest,dim%Dim)){
     potential2 = find_helper(subroot->right,query,(dim+1)%Dim);
   }
   //if potential2 is smaller
   if (shouldReplace(query,currentBest,potential2)){
     currentBest = potential2;
   }
   std::cout <<currentBest[0] << std::endl;
  return currentBest;//end left case
  }

  //go to right subtree
  else{
    if (subroot->right == NULL){
      currentBest = potential;
    }else{
      currentBest = find_helper(subroot->right,query,(dim+1)%Dim);
      //if potential is smaller
      if (shouldReplace(query,currentBest,potential)){
        currentBest = potential;
      }
    }
   //check if go to left subtree
   if (subroot->left!= NULL &&
     smallerDimVal(subroot->left->point,currentBest,dim%Dim)){
     potential2 = find_helper(subroot->left,query,(dim+1)%Dim);
   }
   //if potential2 is smaller
   if (shouldReplace(query,currentBest,potential2)){
     currentBest = potential2;
   }
  return currentBest;
  }

}
*/

template <int Dim>
void KDTree<Dim>::findNN_helper( const Point<Dim>& query, Point<Dim> & currentBest, KDTreeNode * subroot, int dim ) const{
  if( subroot == NULL ){
    return;
  }

  bool isPathLeft;

  if( smallerDimVal(query, subroot->point, dim )){
    isPathLeft = true;
    findNN_helper( query, currentBest, subroot->left, (dim+1)%Dim );
  }
  else{
    isPathLeft = false;
    findNN_helper( query, currentBest, subroot->right, (dim+1)%Dim );
  }

  if( shouldReplace( query, currentBest, subroot->point ) ){
    currentBest = subroot->point;
  }

  double currentRadius = 0;
  for( unsigned i=0; i<Dim; i++ ){
    currentRadius += (currentBest[i] - query[i])*(currentBest[i] - query[i]);
  }

  double dist = (subroot->point[dim] - query[dim])*(subroot->point[dim] - query[dim]);

  if( dist <= currentRadius ){
    KDTreeNode * tmp;
    if( isPathLeft ) tmp = subroot->right;
    else tmp = subroot->left;
    findNN_helper( query, currentBest, tmp, (dim+1)%Dim );
  }

}

template <int Dim>
Point<Dim> KDTree<Dim>::findNearestNeighbor(const Point<Dim>& query) const
{
    /**
     * @todo Implement this function!
     */
     //Point<Dim> querycopy = query;
    //return find_helper(root,querycopy,0);
    //return Point<Dim>();
    Point<Dim> currentBest = root->point;
    findNN_helper( query, currentBest, root, 0 );
    return currentBest;
}





//helper function: copy destroy
template <int Dim>
typename KDTree<Dim>::KDTreeNode* KDTree<Dim>::copy(KDTreeNode *otherroot){
    if (otherroot == NULL)  return NULL;
    //copy the node's pointer and its children
    KDTreeNode *myroot = new KDTreeNode();
    myroot->point = otherroot->point;
    myroot->left = copy(otherroot->left);
    myroot->right = copy(otherroot->right);
    return myroot;
}


template <int Dim>
void KDTree<Dim>::destroy(KDTreeNode *myroot){
    if (myroot == NULL) return;
    destroy(myroot->left);
    destroy(myroot->right);
    delete myroot;
    myroot = NULL;
}
