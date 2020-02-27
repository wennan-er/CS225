#include "TreeNode.h"
#include <iostream>

TreeNode * getSmallerNode(TreeNode* root){
  TreeNode* temp = root;
  while(temp->left_!=NULL){
    temp = temp->left_;
  }
  return temp;
}

TreeNode * deleteNode(TreeNode* root, int key) {
  // your code here
  if (root==NULL){return NULL;}
  else if (key < root->val_){
    root->left_ = deleteNode(root->left_, key);
  }
  else if(key > root->val_){
    root->right_ = deleteNode(root->right_, key);
  }
  else {
    //no children
    if (root->left_==NULL &&root->right_==NULL){
      delete root;
      root = NULL;
      return NULL;
    }
    //two children
    else if(root->left_!=NULL &&root->right_!=NULL){
      TreeNode* temp = getSmallerNode(root->right_);
      root->val_ = temp->val_;
      root->right_ = deleteNode(root->right_,temp->val_);
    }
    //one children-only have left children
    else if(root->left_!=NULL &&root->right_==NULL){
       TreeNode* temp = root->left_;
       delete root;
       root = NULL;
       return temp;
    }
    else if(root->left_==NULL &&root->right_!=NULL){
      TreeNode* temp = root->right_;
      delete root;
      root = NULL;
      return temp;
    }
  }
  return root;
}

void inorderPrint(TreeNode* node)
{
    if (!node)  return;
    inorderPrint(node->left_);
    std::cout << node->val_ << " ";
    inorderPrint(node->right_);
}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}
