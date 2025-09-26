#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Stack
{
private:
    vector<T> stack;

public:
    void push(T data)
    {
        stack.push_back(data);
    }
    void pop()
    {
        stack.pop_back();
    }
    T get()
    {
        return stack.back();
    }
    ~Stack()
    {
        stack.clear();
    }
};