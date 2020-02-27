#include <vector>
#include "BTreeNode.h"


std::vector<int> traverse(BTreeNode* root) {
    // your code here
    int index;
    std::vector<int> v;
    if (root->is_leaf_==true){
      for(auto t=root->elements_.begin(); t!=root->elements_.end(); ++t){
        v.push_back(*t);
      }
      return v;
    }

    for (index = 0; index < int(root->elements_.size());index++){
      // If this is not leaf, then before push_back elements_[index],
        // traverse the subtree rooted with children_[index].

      if (root->is_leaf_==false){
        std::vector<int> vec = traverse(root->children_[index]);
        for(auto t=vec.begin(); t!=vec.end(); ++t){
          v.push_back(*t);
        }
        v.push_back(root->elements_[index]);
      }
    }
     // push_back tree rooted with last child
    if (root->is_leaf_==false){
      std::vector<int> vec = traverse(root-> children_[index]);
      for(auto t=vec.begin(); t!=vec.end(); ++t){
        v.push_back(*t);
      }
    }
    return v;
}
