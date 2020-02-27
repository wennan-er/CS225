
/**
 * @file heap.cpp
 * Implementation of a heap class.
 */
 #include <iostream>
 #include <cmath>

template <class T, class Compare>
size_t heap<T, Compare>::root() const
{
    // @TODO Update to return the index you are choosing to be your root.
    return 1;
}

template <class T, class Compare>
size_t heap<T, Compare>::leftChild(size_t currentIdx) const
{
    // @TODO Update to return the index of the left child.
    //if (2*currentIdx<= capacity)
    return 2*currentIdx;
    //else return 0;
}

template <class T, class Compare>
size_t heap<T, Compare>::rightChild(size_t currentIdx) const
{
    // @TODO Update to return the index of the right child.
    //if (2*currentIdx+1<= capacity)
    return 2*currentIdx+1;
    //else return 0;
}

template <class T, class Compare>
size_t heap<T, Compare>::parent(size_t currentIdx) const
{
    // @TODO Update to return the index of the parent.
    return std::floor(currentIdx/2);
}

template <class T, class Compare>
bool heap<T, Compare>::hasAChild(size_t currentIdx) const
{
    // @TODO Update to return whether the given node has a child
    size_t left = leftChild(currentIdx);
    if (left <= capacity) return true;
    else return false;
}

template <class T, class Compare>
size_t heap<T, Compare>::maxPriorityChild(size_t currentIdx) const
{
    // @TODO Update to return the index of the child with highest priority
    ///   as defined by higherPriority()
    size_t left = leftChild(currentIdx);
    size_t right = rightChild(currentIdx);
    if (left <= capacity && right <= capacity){
    if (_elems[left]<= _elems[right]) return left;
    else return right;
  }
  return left;
}

template <class T, class Compare>
void heap<T, Compare>::heapifyDown(size_t currentIdx)
{
    // @TODO Implement the heapifyDown algorithm.
    if (!hasAChild(currentIdx)) return;
    size_t minChildIndex = maxPriorityChild(currentIdx);
    if (higherPriority(_elems[minChildIndex],_elems[currentIdx])){
      std::swap(_elems[currentIdx],_elems[minChildIndex]);
      heapifyDown(minChildIndex);
    }
}

template <class T, class Compare>
void heap<T, Compare>::heapifyUp(size_t currentIdx)
{
    if (currentIdx == root())
        return;
    size_t parentIdx = parent(currentIdx);
    if (higherPriority(_elems[currentIdx],_elems[parentIdx])) {
        std::swap(_elems[currentIdx], _elems[parentIdx]);
        heapifyUp(parentIdx);
    }
}

template <class T, class Compare>
heap<T, Compare>::heap()
{
    // @TODO Depending on your implementation, this function may or may
    ///   not need modifying
    _elems.push_back(T());
    capacity = 0;
}

template <class T, class Compare>
heap<T, Compare>::heap(const std::vector<T>& elems)
{
    // @TODO Construct a heap using the buildHeap algorithm
    // std::cout << "i have started" << std::endl;

    capacity = elems.size();
    _elems = elems;
    _elems.insert(_elems.begin(), T());
    for (size_t i = parent(capacity); i > 0 ; i--){
      heapifyDown(i);
    }
    // std::cout << "i have finished" << std::endl;
}

template <class T, class Compare>
T heap<T, Compare>::pop()
{
    // @TODO Remove, and return, the element with highest priority
    T minValue = _elems[1];
    _elems[1] = _elems[capacity];
    _elems.pop_back();
    capacity--;
    heapifyDown(1);
    return minValue;
}

template <class T, class Compare>
T heap<T, Compare>::peek() const
{
    // @TODO Return, but do not remove, the element with highest priority
    if (_elems.size() == 1) return T();
    return _elems[1];
}

template <class T, class Compare>
void heap<T, Compare>::push(const T& elem)
{
    // @TODO Add elem to the heap
    _elems.push_back(elem);
    capacity++;
    heapifyUp(capacity);
}

template <class T, class Compare>
void heap<T, Compare>::updateElem(const size_t & idx, const T& elem)
{
    // @TODO In-place updates the value stored in the heap array at idx
    // Corrects the heap to remain as a valid heap even after update
    _elems[idx] = elem;
    heapifyDown(idx);
    heapifyUp(idx);

}


template <class T, class Compare>
bool heap<T, Compare>::empty() const
{
    // @TODO Determine if the heap is empty
    return (capacity!=0);
}

template <class T, class Compare>
void heap<T, Compare>::getElems(std::vector<T> & heaped) const
{
    for (size_t i = root(); i < _elems.size(); i++) {
        heaped.push_back(_elems[i]);
    }
}
