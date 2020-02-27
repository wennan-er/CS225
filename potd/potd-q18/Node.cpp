#include "Node.h"

void mergeList(Node *first, Node *second) {
  // your code here!
  Node * tmp = new Node();
  tmp->data_ = -1;
  tmp->next_ = NULL;
  Node * third = tmp;


  while (first && second){
    third->next_ = first;
    first = first->next_;
    third = third->next_;

    third->next_ = second;
    second = second->next_;
    third = third->next_;
  }
  if (!first){
    third->next_ = second;
  }else{
      third->next_ = first;
    }
  first = tmp->next_;
  delete tmp;



}

Node::Node() {
    numNodes++;
}

Node::Node(const Node &other) {
    this->data_ = other.data_;
    this->next_ = other.next_;
    numNodes++;
}

Node::~Node() {
    numNodes--;
}

int Node::numNodes = 0;
