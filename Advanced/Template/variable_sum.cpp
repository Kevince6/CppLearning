#include <iostream>
#include <vector>
using namespace std;
/*
    ... Args      声明一个模板参数包
    Args ... args  定义函数参数包
    args ...  使用参数包时候展开
    args + ...   C++17引入,意思是用加号将所有参数串联起来.*/

template <typename... Args> // C++17 折叠表达式写法
auto sum(Args... args)
{
    return (... + args);
}

template <typename T>
T Mysum(T val)
{
    return val;
}

template <typename T, typename... Rest>
T Mysum(T first, Rest... rests)
{
    return first + Mysum(rests...);
}

int main()
{
    auto s1 = sum(1, 7, 2.5, 0);
    auto s2 = sum(1, 7, 2.5, 0);
    cout << s1 << endl
         << s2 << endl;
    return 0;
}