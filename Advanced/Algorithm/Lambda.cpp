// auto f = [capture](parameters){}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    auto f = []() // һ��lambda����f
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
    auto f3 = [x, y](int a, int b) // ����x,y�ڶ����ʱ�򱻲���,ֵ�ǹ̶���,���������������ж��ı䡣
    {
        return a * x + b * y;
    };
    auto f4 = [&x, &y](int a, int b) // ���������ò���,��ʵ�ʱ����,���ֲ�����Ի��ʹ�á�
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
    sort(arr.begin(), arr.end(), [](int a, int b) // ����lambda����,��vector arr���н�������.
         { return a > b; });
    for (auto &x : arr)
        cout << x << ' ';
    cout << endl;
    return 0;
}