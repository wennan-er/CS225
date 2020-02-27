#ifndef TREE_CPP
#define TREE_CPP

#include "tree.h"

template <class T>
Tree<T>::Iterator::Iterator(Tree::Node *root) : curr_(root) {
	// TODO: your code here
  Node* cur = root;
	while (cur!=NULL){
		s.push(cur);
		cur = cur->right_;
	}
	if (s.empty()){
		curr_ = NULL;
	}else{
		curr_ = s.top();
	}
	while (curr_ && curr_->data_ == NULL){
		add_helper();
	}
}

template <class T>
void Tree<T>::Iterator::add_helper(){
  if (!s.empty()){
		Node* topItem = s.top();
		Node* cur = topItem->left_;
		s.pop();
		//add
		while (cur!=NULL){
			s.push(cur);
			cur = cur->right_;
		}
		if (s.empty()){
			curr_ = NULL;
		}else{
			curr_ = s.top();
		}
	}
}

template <class T>
typename Tree<T>::Iterator & Tree<T>::Iterator::operator++() {
	// TODO: your code here
  add_helper();
	while (curr_ && curr_->data_ == NULL){
		add_helper();
	}
	return *this;
}

template <class T>
T Tree<T>::Iterator::operator*() const {
	// TODO: your code here
	if (curr_ == NULL)return T();
	return curr_->data_;
}



/*******************
 ** PROVIDED CODE **
 *******************/
template <class T>
bool Tree<T>::Iterator::operator!=(const Tree<T>::Iterator &other) {
	return !(curr_ == other.curr_);
}

template <class T>
typename Tree<T>::Iterator Tree<T>::begin() {
	return Iterator(root_);
}

template <class T>
typename Tree<T>::Iterator Tree<T>::end() {
	return Iterator(NULL);
}

#endif
