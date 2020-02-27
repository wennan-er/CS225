#pragma once
#include <queue>
#include <cstddef>
#include <iostream>
class Queue {
    public:
        int size() const;
        bool isEmpty() const;
        void enqueue(int value);
        int dequeue();
        Queue();
        //~Queue();
    private:
      std::queue<int> myqueue;
};
