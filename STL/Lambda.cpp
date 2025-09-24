// auto f = [capture](parameters){}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    auto f = []() // 一个lambda函数f
    {
        cout << "Hello!" << endl;
        ;
    };
    f();

    int x = 10;
    int y = 20;
    auto f1 = [x, y]()
    {
        return x + y;
    };
    auto f2 = [&x, &y]()
    {
        return ++x + ++y;
    };
    auto f3 = [x, y](int a, int b) // 这里x,y在定义的时候被捕获,值是固定的,不随后续程序的运行而改变。
    {
        return a * x + b * y;
    };
    auto f4 = [&x, &y](int a, int b) // 这里是引用捕获,在实际编程中,两种捕获可以混合使用。
    {
        return a * x + b * y;
    };
    cout << f1() << endl;
    cout << f2() << endl;
    cout << x << ' ' << y << endl;
    cout << f3(2, 3) << endl;
    cout << f4(2, 3) << endl;

    vector<int> arr = {2, 1, 6, 4, 5};
    sort(arr.begin(), arr.end());
    for (auto &x : arr)
        cout << x << ' ';
    cout << endl;
    sort(arr.begin(), arr.end(), [](int a, int b) // 引入lambda规则,对vector arr进行降序排序.
         { return a > b; });
    for (auto &x : arr)
        cout << x << ' ';
    cout << endl;
    return 0;
}