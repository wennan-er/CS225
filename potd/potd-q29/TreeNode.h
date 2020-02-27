#pragma once

#include <cstddef>

// Definition for a binary tree node.
struct TreeNode {
    int val_;
    TreeNode *left_;
    TreeNode *right_;
    TreeNode(int x) {
      left_ = NULL;
      right_ = NULL;
      val_ = x;
    }
};

TreeNode * getSmallerNode(TreeNode* root);
TreeNode * deleteNode(TreeNode* root, int key);

void inorderPrint(TreeNode* node);

void deleteTree(TreeNode* root);
