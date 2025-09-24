#include <iostream>
#include <list> //STL���ṩ��list��˫������
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
    s.emplace(2); // emplace��push�����Ƶ�
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
    auto it = ++L.begin(); // ��ȡ����������it,ָ��ڶ�������6,ʼ��ָ������
    L.insert(it, 92);      // ����ʱ��itǰ���롣
    for (auto &x : L)
        cout << x << ' ';
    cout << endl;
    L.erase(++L.begin());
    for (auto &x : L)
        cout << x << ' ';
    cout << endl;

    //------�����÷�------//
    b.unique();           // ɾ�������ظ�Ԫ��(��һ��)
    b.remove(87);         // ɾ������87��Ԫ��
    L.splice(L.end(), b); // ��b����Lβ����b��ɿ�
    L.sort();             // ����
    for (auto &x : L)
        cout << x << "->";
    cout << "NULL" << endl;

    return 0;
}