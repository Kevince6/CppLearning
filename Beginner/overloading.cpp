// 本节初步学习Cpp中的函数重载
#include <iostream>
using namespace std;

void print(int x)
{
    cout << "integar:" << x << endl;
}

void print(double x)
{
    cout << "double:" << x << endl;
}

void print(string x)
{
    cout << "string:" << x << endl;
}

void print(string x, int s)
{
    cout << "Name:" << x << endl;
    cout << "Score:" << s << endl;
}

int main()
{
    int a = 5;
    double b = 7.82;
    string name = "Richard";
    int score = 98;
    print(a);
    print(b);
    print(name);
    print(name, score);
    return 0;
}