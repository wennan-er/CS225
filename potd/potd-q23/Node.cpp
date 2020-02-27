#include "Node.h"
#include <map>
#include <iostream>
using namespace std;

Node *listSymmetricDifference(Node *first, Node *second) {
  // your code here

  map<int,int> map1;
  map<int,int> map2;
  map<int,int> map3;
  Node * p1 = first;
  Node * p2 = second;

  Node * head = NULL;
  Node *hhhead = NULL;


  while (p1!=NULL){
     map1[p1->data_] = 1;
     map3[p1->data_] = 1;
     p1= p1->next_;
  }
  while (p2!=NULL){
     map2[p2->data_] = 1;
     map3[p2->data_] = 1;
     p2= p2->next_;
  }

  map<int, int>::iterator it1;
         for (it1 = map3.begin(); it1 != map3.end(); it1++)
         {
              if (map1.find(it1->first) == map1.end()){
                Node * tmp = new Node();
                tmp->data_ = it1->first;
                tmp->next_ = NULL;
                if (head==NULL){
                  head = tmp;
                  hhhead = head;
                }else{
                  head->next_ = tmp;
                  head = head->next_;
                }
              }
         }
         map<int, int>::iterator it2;
                for (it2 = map3.begin(); it2 != map3.end(); it2++)
                {
                     if (map2.find(it2->first) == map2.end()){
                       Node * tmp = new Node();
                       tmp->data_ = it2->first;
                       tmp->next_ = NULL;
                       if (head==NULL){
                         head = tmp;
                         hhhead = head;
                       }else{
                         head->next_ = tmp;
                         head = head->next_;
                       }
                     }
                }
  return hhhead;
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
