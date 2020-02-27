#include "TreeNode.h"

#include <cstddef>
#include <iostream>
using namespace std;

TreeNode::TreeNode() : left_(NULL), right_(NULL) { }

int TreeNode::getHeight() {
  if (this==NULL){
    return -1;
  }
  if (left_ == NULL && right_ == NULL){
    return 0;
  }
  return 1 + max(left_->getHeight(),right_->getHeight());
}
