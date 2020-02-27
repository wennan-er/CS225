#include "potd.h"
#include <iostream>

void insertSorted(Node **head, Node *insert) {

  if (*head == NULL){
    *head = insert;
  }else{
    if ((*head)->data_ < insert->data_){
      Node **temp;
      temp = &((*head)->next_);

      insertSorted(temp, insert);
    }else{
      insert->next_ = *head;
      *head = insert;
    }
  }

}
/*
Node* current;

if (*head == NULL || (*head)->data_ >= insert->data_) {
   insert->next_ = *head;
   *head = insert;
 } else {

   current = *head;
   while (current -> next_ != NULL && current->next_->data_ < insert->data_) {
       current = current->next_;
     }
     insert->next_ = current->next_;
     current->next_ = insert;
   }
}
*/
