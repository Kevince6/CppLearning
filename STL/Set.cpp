// ����ѧϰC++����std::set��ʹ��
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    //-----1.��ʼ��------//
    vector<int> v = {1, 5, 2, 8, 9};
    set<int> s1 = {2, 3, 5, 7, 9};
    set<int> s2(s1);                 // ��s1����
    set<int> s3(v.begin(), v.end()); // ��v��������Ȼ��Ҳ�����Ȳ���ʼ��
    //------2.��������------//
    s1.insert(10);
    s1.insert(4);
    s1.erase(5);
    if (s1.find(9) != s1.end()) // ���ص�����ָ��9����������ڣ�����s1.end()
        cout << "9 Founded." << endl;
    cout << s2.empty() << endl;
    cout << s3.size() << endl;
    cout << s3.count(6) << endl;
    for (int x : s1)
        cout << x << ' ';
    cout << endl;
    return 0;
}

// �����ص㣺���ظ����Զ�����