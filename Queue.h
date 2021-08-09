#ifndef ALGO_QUEUE_H
#define ALGO_QUEUE_H
#include "IO.h"
using namespace std;


// A class of queue
class Queue
{
    int *arr;       // array to store queue elements
    int capacity;   // maximum capacity of the queue
    int front;      // front points to the front element in the queue (if any)
    int rear;       // rear points to the last element in the queue
    int count;      // current size of the queue

public:
    Queue(int size = 0);     // constructor
    ~Queue();                   // destructor

    int dequeue();
    void enqueue(int x);
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
};

#endif //ALGO_QUEUE_H
