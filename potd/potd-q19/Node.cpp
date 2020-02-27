#include "Node.h"
#include <iostream>
/** Create a new node and add it to the list, while keeping the list sorted.
*/


Node *insertSorted(Node *first, int data) {
    // your code here
    Node * tmp = new Node();
    tmp->data_ = data;
    tmp->next_ = NULL;

    if (first == NULL){
      first = tmp;
      return tmp;
    }
    Node * head = first;
    Node * prev = first;
    Node * cur = first;

    if (prev==cur){
      if (data < cur->data_){
        tmp->next_ = cur;
        head = tmp;
        prev = head;

        return head;
      }
      if (data == cur->data_){
        delete tmp;
        return head;
      }
      if (data > cur->data_){
        cur = cur->next_;
      }
    }

    while(cur!=NULL && (prev!=cur)){
      if (data < cur->data_ ){
        tmp->next_ = cur;
        prev->next_ = tmp;

        return head;
      }
      if (data == cur->data_){
        delete tmp;
        return head;
      }
      if (data > cur->data_){
        cur = cur->next_;
        prev = prev->next_;
      }
    }
    //std::cout << tmp->data_ << std::endl;
    cur = tmp;
    prev->next_ = tmp;


    return head;
}

/** Creates a new list (containing new nodes, allocated on the heap)
	that contains the set union of the values in both lists.
*/
Node *listUnion(Node *first, Node *second) {
    Node *out = NULL;

    while (first != NULL) {

      out = insertSorted(out,first->data_);

      first = first->next_;
        // your code here
        // hint: call insertSorted and update l1

    }

    while (second != NULL) {
      out = insertSorted(out,second->data_);
      second = second->next_;
        // your code here
    }

    return out;
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
