/**
 * @file binarytree.cpp
 * Definitions of the binary tree functions you'll be writing for this lab.
 * You'll need to modify this file.
 */
#include "TreeTraversals/InorderTraversal.h"
#include <iostream>
#include <iterator>
#include <stack>
#include <numeric>
/**
 * @return The height of the binary tree. Recall that the height of a binary
 *  tree is just the length of the longest path from the root to a leaf, and
 *  that the height of an empty tree is -1.
 */
template <typename T>
int BinaryTree<T>::height() const
{
    // Call recursive helper function on root
    return height(root);
}

/**
 * Private helper function for the public height function.
 * @param subRoot
 * @return The height of the subtree
 */
template <typename T>
int BinaryTree<T>::height(const Node* subRoot) const
{
    // Base case
    if (subRoot == NULL)
        return -1;

    // Recursive definition
    return 1 + std::max(height(subRoot->left), height(subRoot->right));
}

/**
 * Prints out the values of the nodes of a binary tree in order.
 * That is, everything to the left of a node will be printed out before that
 * node itself, and everything to the right of a node will be printed out after
 * that node.
 */
template <typename T>
void BinaryTree<T>::printLeftToRight() const
{
    // Call recursive helper function on the root
    printLeftToRight(root);

    // Finish the line
    std::cout << std::endl;
}

/**
 * Private helper function for the public printLeftToRight function.
 * @param subRoot
 */
template <typename T>
void BinaryTree<T>::printLeftToRight(const Node* subRoot) const
{
    // Base case - null node
    if (subRoot == NULL)
        return;

    // Print left subtree
    printLeftToRight(subRoot->left);

    // Print this node
    std::cout << subRoot->elem << ' ';

    // Print right subtree
    printLeftToRight(subRoot->right);
}

/**
 * Flips the tree over a vertical axis, modifying the tree itself
 *  (not creating a flipped copy).
 */

 template <typename T>
 void BinaryTree<T>::mirrorhelper(Node* root1) {

   if (root1!=NULL){
     if ((root1->left == NULL) && (root1->right == NULL)){
       return;
     }
     else if ((root1->left != NULL) && (root1->right != NULL)){
       BinaryTree::Node * tmp = root1->right;
       root1->right = root1->left;
       root1->left = tmp;
       mirrorhelper(root1->left);
       mirrorhelper(root1->right);
     }
     else if ((root1->left != NULL) && (root1->right == NULL)){
       root1->right = root1->left;
       root1->left = NULL;
       return;
     }
     else{
       root1->left = root1->right;
       root1->right = NULL;
       return;
     }
   }

 }


template <typename T>
void BinaryTree<T>::mirror()
{
    //your code here
    return mirrorhelper(root);
}




/**
 * isOrdered() function iterative version
 * @return True if an in-order traversal of the tree would produce a
 *  nondecreasing list output values, and false otherwise. This is also the
 *  criterion for a binary tree to be a binary search tree.
 */
template <typename T>
bool BinaryTree<T>::isOrderedIterative() const
{
    // your code here
    InorderTraversal<T> iot(this->getRoot());
    T tmp = (*iot.begin())->elem;
    for (typename TreeTraversal<T>::Iterator it = iot.begin(); it != iot.end(); ++it) {
        if (tmp > ((*it)->elem)){
          return false;
        }
        tmp = ((*it)->elem);
    }

    return true;

}

/**
 * isOrdered() function recursive version
 * @return True if an in-order traversal of the tree would produce a
 *  nondecreasing list output values, and false otherwise. This is also the
 *  criterion for a binary tree to be a binary search tree.
 */
//find max

template <typename T>
T BinaryTree<T>::findmax(const Node *subRoot) const{
  if (subRoot!=NULL){
    T currentMax = subRoot->elem;
    if(subRoot->left!=NULL){
    currentMax = std::max(currentMax,findmax(subRoot->left));
  }
    if(subRoot->right!=NULL){
    currentMax = std::max(currentMax,findmax(subRoot->right));
  }
  return currentMax;
}else{
  return -1000;
}

}

//find min
template <typename T>
T BinaryTree<T>::findmin(const Node *subRoot) const{
  if (subRoot!=NULL){
    T currentMin = subRoot->elem;
    if(subRoot->left!=NULL){
    currentMin = std::min(currentMin,findmin(subRoot->left));
   }
    if(subRoot->right!=NULL){
    currentMin = std::min(currentMin,findmin(subRoot->right));
   }
   return currentMin;
 }else{
   return 1000;
 }
  }



template <typename T>
bool BinaryTree<T>::isOrderedRecursive(Node *subRoot) const
{
  if (subRoot==NULL){
    return true;
  }
  if (!isOrderedRecursive(subRoot->left)){
    return false;
  }
  if (!isOrderedRecursive(subRoot->right)){
    return false;
  }

  if (findmax(subRoot->left) > subRoot->elem){
    return false;
  }
  if (findmin(subRoot->right) < subRoot->elem){
    return false;
  }
  return true;
}

template <typename T>
bool BinaryTree<T>::isOrderedRecursive() const
{
    // your code here
    return isOrderedRecursive(root);
}


/**
 * creates vectors of all the possible paths from the root of the tree to any leaf
 * node and adds it to another vector.
 * Path is, all sequences starting at the root node and continuing
 * downwards, ending at a leaf node. Paths ending in a left node should be
 * added before paths ending in a node further to the right.
 * @param paths vector of vectors that contains path of nodes
 */

template <typename T>
void BinaryTree<T>::Pathhelper(Node * node,std::vector<std::vector<T>>& path,
                               std::vector<T> pathtmp
                              ) const{
   if (node==NULL){
     return;
   }
   pathtmp.push_back(node->elem);
   if (node->left == NULL && node->right == NULL){
      path.push_back(pathtmp);
      return;
   }
   else{
     Pathhelper(node->left, path, pathtmp);
     Pathhelper(node->right, path, pathtmp);
   }
}
template <typename T>
void BinaryTree<T>::getPaths(std::vector<std::vector<T>>& paths) const
{
    // your code here
    std::vector<T> pathtmp;
    Pathhelper(root,paths,pathtmp);

}


/**
 * Each node in a tree has a distance from the root node - the depth of that
 * node, or the number of edges along the path from that node to the root. This
 * function returns the sum of the distances of all nodes to the root node (the
 * sum of the depths of all the nodes). Your solution should take O(n) time,
 * where n is the number of nodes in the tree.
 * @return The sum of the distances of all nodes to the root
 */

/*
 template <typename T>
 int BinaryTree<T>::sumDistances(Node * subnode,std::vector<T> pathtmp) const
 {
     // your code here
     if (subnode==NULL){
       return 0;
     }

     for(unsigned int i = 0; i < pathtmp.size(); i++){
		      pathtmp[i]++;
	    }
      std::cout << 1111111111<<std::endl;
      pathtmp.push_back(0);
     if (subnode->left == NULL && subnode->right == NULL){
        //return accumulate(pathtmp.begin(),pathtmp.end(),0);

        for(unsigned int i = 0; i < pathtmp.size(); i++){
            std::cout << pathtmp[i] << std::endl;

   	    }
        return accumulate(pathtmp.begin(),pathtmp.end(),0);
     }
     else{
     return sumDistances(subnode->left,pathtmp)+sumDistances(subnode->right,pathtmp);
 }
}
*/



template <typename T>
int BinaryTree<T>::sumDistances() const
{
    // your code here
    //int total = height(root);
    //std::vector<T> pathtmp;
    //return sumDistances(root,pathtmp);
    return 0;
}
