#include <vector>
#include "BTreeNode.h"
#include <iostream>

BTreeNode* find(BTreeNode* root, int key) {
    // Your Code Here
    unsigned i = 0;
    while(i < root->elements_.size() &&key > root->elements_[i]){
      i++;
    }
  
    if (i < root->elements_.size() && key == root->elements_[i]){
      return root;
    }
    if (root->is_leaf_){
      return NULL;
    }else{
      BTreeNode * nextchild = root->children_[i];

      return find(nextchild,key);
    }
}
