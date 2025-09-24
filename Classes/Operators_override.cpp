#include <iostream>
#include <vector>
using namespace std;

class Vector2
{
private:
    int x;
    int y;

public:
    Vector2(int x = 0, int y = 0) : x(x), y(y) {} // 这是一个初始化语句，无需构造函数就可以初始化，适合针对于const成员和引用成员。
    Vector2 operator+(const Vector2 &other)
    { // 要习惯const &的参数传递模式。
        return Vector2(x + other.x, y + other.y);
    }
    void PrintVector()
    {
        cout << '(' << x << ',' << y << ')' << endl;
    }
    friend ostream &operator<<(ostream &os, const Vector2 v); // 在类内对<<的重载做一个说明，返回类型是输出流ostream，需要一个参数ostream&
};

ostream &operator<<(ostream &os, const Vector2 v)
{
    return os << '(' << v.x << ',' << v.y << ')' << endl;
}

int main()
{
    Vector2 a(1, 2);
    Vector2 b(3, 4);
    Vector2 c = a + b;
    c.PrintVector();   // 通过调用类内方法来输出c.
    cout << c << endl; // 通过对输出运算符<<的重载来输出c.
    return 0;
}

// 1.运算符重载可以是成员函数，也可以是全局函数(有时，运算符的其中一边不属于这个类)
// 2.常见的可以重载的运算符有:+ - * / % == [] () << >>
// 3.友元函数friend. 正常来说，类外函数是不能访问private成员的，但是当不得不访问时，就可以定义友元函数。