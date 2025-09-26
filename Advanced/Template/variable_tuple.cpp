#include <iostream>
#include <vector>
using namespace std;

template <typename T>
using Vec = vector<T>;

template <typename... Args> // 就是让对应的类可以有多种类型，比如<int double string>
class MyCounter
{
public:
    void printSize()
    {
        cout << sizeof...(Args) << endl; // 用折叠表达式。
    }
};

template <typename... Args> // 定义基类，空的tupple
class MyTuple;

template <typename First, typename... Rest> // 特化类，至少有一个参数
class MyTuple<First, Rest...>
{
public:
    First head;
    MyTuple<Rest...> tail;
    MyTuple(First head, Rest... rests) : head(head), tail(rests...) {};
};

template <typename Last> // 递归结束类，最后一个元素,作特化(特殊处理)
class MyTuple<Last>
{
public:
    Last head;
    MyTuple(Last head) : head(head) {};
};

int main()
{
    MyCounter<int, double, float, string, vector<int>, Vec<string>> mct;
    MyTuple<int, double, string> mtp(12, 3.14, "Cherry");
    mct.printSize();
    cout << mtp.head << mtp.tail.head << mtp.tail.tail.head << endl;
    return 0;
}
