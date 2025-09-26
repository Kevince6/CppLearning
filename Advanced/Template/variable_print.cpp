#include <iostream>
using namespace std;

template <typename... Args>
void print(Args... parameters)
{
    (cout << ... << parameters) << endl;
}

template <typename T>
void Myprint(T args)
{
    cout << args;
}

template <typename T, typename... Rest>
void Myprint(T args, Rest... rest)
{
    cout << args;
    Myprint(rest...);
}

int main()
{
    print("hello", ' ', 86, ' ', 90.5);
    Myprint("hello", ' ', 86, ' ', 90.5);
    return 0;
}