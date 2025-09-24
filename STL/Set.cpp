// 本节学习C++容器std::set的使用
#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    //-----1.初始化------//
    vector<int> v = {1, 5, 2, 8, 9};
    set<int> s1 = {2, 3, 5, 7, 9};
    set<int> s2(s1);                 // 从s1拷贝
    set<int> s3(v.begin(), v.end()); // 从v拷贝，当然，也可以先不初始化
    //------2.基本操作------//
    s1.insert(10);
    s1.insert(4);
    s1.erase(5);
    if (s1.find(9) != s1.end()) // 返回迭代器指向9，如果不存在，返回s1.end()
        cout << "9 Founded." << endl;
    cout << s2.empty() << endl;
    cout << s3.size() << endl;
    cout << s3.count(6) << endl;
    for (int x : s1)
        cout << x << ' ';
    cout << endl;
    return 0;
}

// 两个特点：不重复，自动升序