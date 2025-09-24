#include <iostream>
#include <list> //STL里提供的list是双向链表
#include <queue>
#include <stack>
using namespace std;

int main()
{
    queue<int> q;
    stack<int> s;
    q.push(1);
    q.push(2);
    q.push(3);
    q.pop();
    cout << "Front:" << q.front() << endl;
    cout << "Back:" << q.back() << endl;
    cout << "Size of q:" << q.size() << endl;

    s.push(1);
    s.emplace(2); // emplace和push是类似的
    s.push(6);
    s.pop();
    cout << "Get top:" << s.top() << endl;

    list<int> L = {2, 6, 9, 5, 7};
    list<int> b = {42, 42, 87, 19, 35};
    L.push_back(25);
    L.push_front(62);
    for (auto &x : L)
        cout << x << ' ';
    cout << endl;
    cout << "Front:" << L.front() << " Back:" << L.back() << endl;
    L.pop_back();
    L.pop_front();
    auto it = ++L.begin(); // 获取迭代器对象it,指向第二个整数6,始终指向它。
    L.insert(it, 92);      // 插入时在it前插入。
    for (auto &x : L)
        cout << x << ' ';
    cout << endl;
    L.erase(++L.begin());
    for (auto &x : L)
        cout << x << ' ';
    cout << endl;

    //------特殊用法------//
    b.unique();           // 删除相邻重复元素(留一个)
    b.remove(87);         // 删除所有87的元素
    L.splice(L.end(), b); // 将b插入L尾部，b变成空
    L.sort();             // 排序
    for (auto &x : L)
        cout << x << "->";
    cout << "NULL" << endl;

    return 0;
}