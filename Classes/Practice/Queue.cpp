#include <iostream>
#include <vector>
using namespace std;

class Queue
{
private:
    int front, rear;
    int capacity;
    int *data;

public:
    Queue(int cap = 10)
    {
        capacity = cap;
        front = rear = 0;
        data = new int[capacity];
    }
    void EnQueue(int val)
    {
        if (isFull())
            return;
        data[rear] = val;
        rear = (rear + 1) % capacity;
    }
    void DeQueue()
    {
        if (isEmpty())
            return;
        front = (front + 1) % capacity;
    }
    bool isEmpty()
    {
        return front == rear;
    }
    bool isFull()
    {
        return (rear + 1) % capacity == front;
    }
    int GetLength()
    {
        return (rear + capacity - front) % capacity;
    }
    ~Queue()
    {
        delete[] data;
    }
};

int main()
{
    Queue q(6);
    q.EnQueue(1);
    q.EnQueue(2);
    q.EnQueue(3);
    q.DeQueue();
    cout << q.GetLength() << endl;
    return 0;
}