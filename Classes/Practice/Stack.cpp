#include <iostream>
#include <vector>
using namespace std;

class Stack
{
private:
    int *data;
    int top;
    int capacity;

public:
    Stack(int cap = 10)
    {
        top = -1;
        capacity = cap;
        data = new int[capacity];
    }

    void push_back(int val)
    {
        if (top + 1 == capacity)
        {
            cout << "Full Stack!" << endl;
            return;
        }
        data[++top] = val;
    }

    void pop_out()
    {
        if (isEmpty())
        {
            cout << "Empty Stack!" << endl;
            return;
        }
        top--;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    int GetTop()
    {
        if (isEmpty())
        {
            cout << "Empty Stack!" << endl;
            return -1;
        }
        return data[top];
    }
    int GetCuurentSize()
    {
        return top + 1;
    }
    ~Stack()
    {
        delete[] data;
    }
};

int main()
{
    Stack ss;
    ss.push_back(1);
    ss.push_back(2);
    ss.push_back(3);
    cout << ss.GetTop() << endl;
    ss.pop_out();
    cout << ss.GetTop() << endl;
    ss.pop_out();
    ss.pop_out();
    cout << ss.isEmpty() << endl;
    return 0;
}