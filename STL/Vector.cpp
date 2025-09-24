// 本节我们学习C++中的一个重要容器 vector
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //--------1.初始化-----------//
    vector<int> a;              // 可以给它定义初始容量，如果没有的话就默认为空，push_back的时候自动扩容
    vector<int> b(5, 10);       // b中包含5个初始值为10的int型数据。
    vector<int> c{2, 5, 9, 11}; // 用列表的方式初始化。
    //--------2.基本操作------//
    cout << "Initial Size of a:" << a.size() << endl;
    a.push_back(10);
    a.push_back(20);
    cout << "Size of a after push_back:" << a.size() << endl;
    cout << "First Element Of a: " << a[0] << endl;
    cout << "First Element Of c: " << c.front() << endl;
    cout << "Second Element of c: " << c.at(1) << endl;
    cout << "Last Element of c: " << c.back() << endl;
    b.pop_back();
    cout << "The Capacity Of b:" << b.capacity() << endl;
    cout << "Size of b:" << b.size() << endl;

    //---------3.遍历，插入与删除--------//
    c.insert(c.begin() + 2, 99);       // 在下标2位置，添加元素99. 这里.begin()/.end()返回的是迭代器对象。
    c.erase(c.begin() + 3);            // 删除下标3的元素
    for (int i = 0; i < c.size(); i++) // 传统C的写法。
        cout << c[i] << ' ';
    cout << endl;
    for (int x : c) // 迭代器写法
        cout << x << ' ';
    cout << endl;
    //---------4. 其他用法---------//
    b.clear(); // clear清size，不清capacity
    cout << b.empty() << endl;
    a.swap(c); // 交换vector
    for (int x : a)
        cout << x << ' ';
    cout << endl;
    a.resize(6, 8); // 改为6个size，多出来的补8.
    for (int x : a)
        cout << x << ' ';
    cout << endl;
    int *p = a.data(); //.data()取出vector a的指针，使其可以用指针p像传统C那样操作。
    return 0;
}