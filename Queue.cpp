#include "Queue.h"

// Constructor to initialize a queue
Queue::Queue(int size)
{
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}

// Destructor to free memory allocated to the queue
Queue::~Queue() {
    delete[] arr;
}

// Utility function to dequeue the front element
int Queue::dequeue()
{
    // check for queue underflow
    if (isEmpty())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }
    int res = arr[front];
    cout << "Removing " << arr[front] << endl;

    front = (front + 1) % capacity;
    count--;
    return res;
}

// Utility function to add an item to the queue
void Queue::enqueue(int item)
{
    // check for queue overflow
    if (isFull())
    {
        cout << "Overflow\nQueue is full\n" << endl;
        exit(EXIT_FAILURE);
    }

    cout << "Inserting " << item << endl;

    rear = (rear + 1) % capacity;
    arr[rear] = item;
    count++;
}

// return the front element of the queue
int Queue::peek()
{
    if (isEmpty())
    {
        cout << "Underflow\nQueue is empty\n";
        exit(EXIT_FAILURE);
    }
    return arr[front];
}

// return the size of the queue
int Queue::size() {
    return count;
}

// check if the queue is empty
bool Queue::isEmpty() {
    return (size() == 0);
}

// check if the queue is full
bool Queue::isFull() {
    return (size() == capacity);
}

