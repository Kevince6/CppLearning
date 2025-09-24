#include <iostream>
using namespace std;

void increment(int &x)
{
    x++;
}

int main()
{
    int a = 6;
    increment(a);
    cout << a;
    return 0;
}