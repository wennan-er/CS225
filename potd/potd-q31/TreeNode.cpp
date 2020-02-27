#include "TreeNode.h"

bool isHeightBalanced(TreeNode* root) {
  // your code here
  if (heighthelper(root) >1){
    return false;
  }
  if (heighthelper(root) <-1){
    return false;
  }
  return true;

}

int heighthelper(TreeNode* root){
   if (root==NULL){
     return -1;
   }
   if (root->left_ == NULL && root->right_ == NULL){
     return 0;
   }
   if (root->left_ == NULL && root->right_!=NULL){
     return 1 + heighthelper(root->right_);
   }
   else if(root->left_ != NULL && root->right_==NULL){
     return 1 + heighthelper(root->left_);
   }
   else{
     return heighthelper(root->left_)- heighthelper(root->right_);
   }
}

void deleteTree(TreeNode* root)
{
  if (root == NULL) return;
  deleteTree(root->left_);
  deleteTree(root->right_);
  delete root;
  root = NULL;
}
