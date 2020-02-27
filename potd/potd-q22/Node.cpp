#include "Node.h"

using namespace std;

Node *listIntersection(Node *first, Node *second) {
  // your code here
  if (!first || !second){
    return NULL;
  }
  Node * cur = NULL;
  Node * head = cur;
  while (first && second){
    if (first->data_ < second->data_){
      first = first->next_;
    }
    else if (first->data_ == second->data_){
     //edge case multiple same duplicated
      if (cur==NULL){
        Node * tmp = new Node();
        tmp->data_ = first->data_;
        tmp->next_ = NULL;
          cur = tmp;
          //head = cur;
          first = first->next_;
          second = second->next_;
        }else{
          if (cur->data_ == first->data_){
            first = first->next_;
            second = second->next_;
         }else{
          Node * tmp = new Node();
          tmp->data_ = first->data_;
          tmp->next_ = NULL;
          cur->next_ = tmp;
          cur = cur->next_;

          first = first->next_;
          second = second->next_;
              }
        }
      }
      else{
        second = second->next_;
      }
    }
  return cur;
}

Node::Node() {
    numNodes++;
}

Node::Node(Node &other) {
    this->data_ = other.data_;
    this->next_ = other.next_;
    numNodes++;
}

Node::~Node() {
    numNodes--;
}

int Node::numNodes = 0;
