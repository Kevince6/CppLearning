// 本节学习Cpp中的函数重载与默认参数
#include <iostream>
using namespace std;

void greet(string name = "Guest", string msg = "Welcome")
{
    cout << msg << ',' << name << '!' << endl;
}

void aputs(int x, int y = 0)
{
    cout << x << ',' << y << endl;
}

int main()
{
    greet();
    string name = "Oliver";
    string msg = "Fku";
    int x = 78;
    greet(name);
    greet(msg);
    greet(name, msg);
    aputs(x);
    return 0;
}

// Overloading和Default Arguement可以同时使用，但需要注意二义性的问题。
// 如： void(int x=0)  与  void() 是二义的， 编译器会报错。