#include "TreeNode.h"

// Your function here
TreeNode *makeFullRight(int n,int index){
  if (n==index){
    TreeNode *no_child = new TreeNode(index,NULL,NULL);
    return no_child;
  }
  else if (n-index == 1){
    TreeNode *lefttmp = new TreeNode(index+1,NULL,NULL);
    TreeNode *one_child = new TreeNode(index,lefttmp,NULL);
    return one_child;
  }
  else if (n-index == 2){
    TreeNode *lefttmp = new TreeNode(index+1,NULL,NULL);
    TreeNode *righttmp = new TreeNode(index+2,NULL,NULL);
    TreeNode *two_child = new TreeNode(index,lefttmp,righttmp);
    return two_child;
  }
    TreeNode *lefttmp = new TreeNode(index+1,NULL,NULL);
    TreeNode *recursive_child = new TreeNode(index,lefttmp,makeFullRight(n,index+2));
  return recursive_child;
}
TreeNode *makeFullRight(int n) {
  return makeFullRight(n,1);
}

// Methods and functions we provide following.
// You should not need to edit this code.

TreeNode::TreeNode(int data, TreeNode *left, TreeNode *right) :
    data_(data), left_(left), right_(right) {}

TreeNode::~TreeNode() {
    if (left_ != NULL)
        delete left_;
    if (right_ != NULL)
        delete right_;
}

bool equal(TreeNode *n1, TreeNode *n2) {
    if (n1 == NULL)
        return n2 == NULL;

    if (n2==NULL)
        return false;

    return (n1->getData() == n2->getData() &&
            equal(n1->getLeft(),n2->getLeft()) &&
            equal(n1->getRight(),n2->getRight()));
}

int TreeNode::getData() const {
    return data_;
}

TreeNode *TreeNode::getLeft() const {
    return left_;
}

TreeNode *TreeNode::getRight() const {
    return right_;
}
