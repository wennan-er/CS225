/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 */

template <class T>
List<T>::List() {
  // @TODO: graded in MP3.1
    head_ = NULL;
    tail_ = NULL;
    length_ = 0;

}

/**
 * Returns a ListIterator with a position at the beginning of
 * the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::begin() const {
  // @TODO: graded in MP3.1
  return List<T>::ListIterator(head_);
}

/**
 * Returns a ListIterator one past the end of the List.
 */
template <typename T>
typename List<T>::ListIterator List<T>::end() const {
  // @TODO: graded in MP3.1
  return List<T>::ListIterator(NULL);
}


/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <typename T>
void List<T>::_destroy() {
<<<<<<< HEAD
   while (head_!=NULL){
     ListNode * nextptr = head_->next;
     delete head_;
     head_ = nextptr;
   }
   head_ = NULL;
   tail_ = NULL;
   length_ = 0;
 }

=======
  while (head_!=NULL){
    ListNode * nextptr = head_ ->next;
    delete head_;
    head_ = nextptr;
  }
  head_ = NULL;
  tail_ = NULL;
  length_ = 0;
}
>>>>>>> b6965dbef76ebb27d806f5ad7ef18c1d52eaf9c1
  /*
  while (head_ != NULL){
    if (head_ == tail_){
      delete head_;
      head_ = NULL;
      tail_ = NULL;
      length_ = 0;
    }
    else{
    while(head_!=tail_){
         head_ = head_->next;
            if (head_!=NULL){
                delete (head_->prev);
            }
          }
<<<<<<< HEAD
        }
=======

     }
>>>>>>> b6965dbef76ebb27d806f5ad7ef18c1d52eaf9c1
  /// @todo Graded in MP3.1
}
}
*/
<<<<<<< HEAD


=======
>>>>>>> b6965dbef76ebb27d806f5ad7ef18c1d52eaf9c1


/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertFront(T const & ndata) {
  /// @todo Graded in MP3.1
  ListNode * newNode = new ListNode(ndata);
  newNode -> next = head_;
  newNode -> prev = NULL;

  if (head_ != NULL) {
    head_ -> prev = newNode;
    head_ = newNode;
  }
  if (tail_ == NULL) {
    tail_ = newNode;
    head_ = newNode;
  }


  length_++;

}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <typename T>
void List<T>::insertBack(const T & ndata) {
  /// @todo Graded in MP3.1
  ListNode * newNode = new ListNode(ndata);
  newNode -> prev = tail_;
  newNode -> next = NULL;

  if (tail_!= NULL){
    tail_ -> next = newNode;
    tail_ = newNode;
  }
  if (head_ == NULL){
    head_ = newNode;
    tail_ = newNode;
  }
  length_++;
}

/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List or ListNode objects!
 *
 * This function is also called by the public split() function located in
 * List-given.hpp
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <typename T>
typename List<T>::ListNode * List<T>::split(ListNode * start, int splitPoint) {
  /// @todo Graded in MP3.1
  if (splitPoint == 0){
    return start;
  }
  ListNode * curr = start;

  for (int i = 0; i < splitPoint && curr != NULL; i++) {
    curr = curr->next;
  }

  if (curr != NULL) {
      curr->prev->next = NULL;
      curr->prev = NULL;
  }

  return curr;
}

/**
 * Modifies the List using the waterfall algorithm.
 * Every other node (starting from the second one) is removed from the
 * List, but appended at the back, becoming the new tail. This continues
 * until the next thing to be removed is either the tail (**not necessarily
 * the original tail!**) or NULL.  You may **NOT** allocate new ListNodes.
 * Note that since the tail should be continuously updated, some nodes will
 * be moved more than once.
 */
template <typename T>
void List<T>::waterfall(){
  ListNode * curr = head_;
  if ((head_!=NULL) && (head_!=tail_)&&(head_->next!=tail_)){
    while(curr->next !=tail_){
      tail_->next = curr->next;
      curr->next->prev = tail_;
      curr->next = curr->next->next;
      curr->next->prev = curr;
      tail_->next->next = NULL;
      tail_ = tail_->next;
      curr = curr->next;
    }
  }
  /// @todo Graded in MP3.1
}

/**
 * Reverses the current List.
 */
template <typename T>
void List<T>::reverse() {
  reverse(head_, tail_);
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
template <typename T>
void List<T>::reverse(ListNode *& startPoint, ListNode *& endPoint) {
  /// @todo Graded in MP3.2

  ListNode * first = startPoint;
  ListNode * last = endPoint;
  ListNode * pre = NULL;
  startPoint = last;
  endPoint = first;

  while (last!=NULL){

    ListNode * tmp = last;
    last = last->prev;
    if (last!=NULL){
    last->next = NULL;
    }
    if (pre==NULL){
      tmp->prev = NULL;
      tmp->next = NULL;
    }else{
      tmp->prev = pre;
      pre->next = tmp;
    }
    pre = tmp;
  }
  pre->next = NULL;

  ListNode *temp = startPoint;


}

/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <typename T>
void List<T>::reverseNth(int n) {
  /// @todo Graded in MP3.2

 //ListNode *headtmp = head_;

 bool flag = false;
  if (head_ !=NULL && n > 1){
    int count = 0;
    ListNode * startblock = head_;
    ListNode * endblock  = head_;
    ListNode * startprev = head_;
    ListNode * endnext = head_;

      while ((size()-count*n) > n){
        for (int i = 0; i < n; i++){
          endnext = endnext->next;
        }
        endblock = endnext->prev;

        endblock->next = NULL;
        endnext->prev = NULL;

        if (flag==false){
          reverse(head_,endblock);
          startblock = head_;
          flag = true;
        }else{
          reverse(startblock,endblock);
        }

        count+=1;

        if (startprev == head_){
          startprev = endblock;
        }else{
          startprev->next = startblock;
          startblock->prev = startprev;
          startprev = endblock;
        }
        startblock = endnext;
      }
      if ((size()-count*n <= n) && (size()-count*n >1)){
        reverse(startblock, tail_);
        count+=1;
        if (startprev!=head_){
          startprev->next = startblock;
          startblock->prev = startprev;
        }
      }
  }
  //head_ = headtmp;
}


/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <typename T>
void List<T>::mergeWith(List<T> & otherList) {
    // set up the current list
    head_ = merge(head_, otherList.head_);
    tail_ = head_;

    // make sure there is a node in the new list
    if (tail_ != NULL) {
        while (tail_->next != NULL)
            tail_ = tail_->next;
    }
    length_ = length_ + otherList.length_;

    // empty out the parameter list
    otherList.head_ = NULL;
    otherList.tail_ = NULL;
    otherList.length_ = 0;
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */

template <typename T>
 typename List<T>::ListNode * List<T>::merge(ListNode * first, ListNode * second) {
   if (first == NULL) {
      return second;
    }
    if (second == NULL) {
      return first;
    }

    ListNode* tmp;
    if (second->data < first->data) {
      tmp = second;
      second = first;
      first = tmp;
    }

      ListNode* cur1 = first;
      ListNode* cur2 = second;
      ListNode* tmp1;
      ListNode* tmp2;

      while (cur2 != NULL) {
        tmp2 = cur2->next;
        while (cur1 != NULL) {
          tmp1 = cur1->next;
          if (cur2->data < cur1->data) {
            cur1->prev->next = cur2;
            cur2->next = cur1;
            cur2->prev = cur1->prev;
            cur1->prev = cur2;
            break;
          }
          else if (tmp1 == NULL && cur2 != NULL) {
              cur1->next = cur2;
              cur2->prev = cur1;
              break;
          }
          cur1 = tmp1;
        }
        if (cur1->next == cur2 && cur2->prev == cur1) {
          break;
        }
        cur2 = tmp2;
      }
      return first;
    }



/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * Called by the public sort function in List-given.hpp
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <typename T>
typename List<T>::ListNode* List<T>::mergesort(ListNode * start, int chainLength) {
  /// @todo Graded in MP3.2


  if (start->next == NULL){
    return start;
  }

  ListNode * list2 = split(start,chainLength/2);
  ListNode * l1 = mergesort(start,chainLength/2);
  ListNode * l2 = mergesort(list2,chainLength/2 + chainLength%2);
  return merge(l1,l2);

}
