#include "TreeNode.h"

TreeNode* findLastUnbalanced(TreeNode* root) {
  // your code here
  if (root==NULL){
    return NULL;
  }
  if (root->left_ == NULL && root->right_==NULL){
    return NULL;
  }
  if (root->left_ == NULL && root->right_!=NULL){
    return 
  }
  if (root->left_ != NULL && root->right_==NULL){

  }
  return NULL;
}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}
