// 本节介绍智能指针的使用。相对于普通指针，智能指针自动内存管理，不用delete
// 一共有三种类型的智能指针，每类指针在使用的时候有一些规定。
// 他们是 unique_ptr shared_ptr weak_ptr
#include <iostream>
#include <memory>
using namespace std;
int main()
{
    unique_ptr<int> p1(new int(10));
    unique_ptr<int> p2 = make_unique<int>(5);
    cout << *p1 << ' ' << *p2 << endl;
    // p2 = p1;  unique_ptr<int> q3 = p1; 这都是不被允许的。unique_ptr不可拷贝
    p2 = move(p1); // 但是unique指针可以移动，这里表示p2改为管理p1指向的内存，p1变为nullptr.
    cout << *p2 << endl;
    if (p1 == nullptr)
        cout << "p1 points at NULL after move operation." << endl;

    shared_ptr<int> sp1 = make_shared<int>(28);
    shared_ptr<int> sp2 = sp1;
    cout << *sp1 << ' ' << *sp2 << endl;
    cout << "Use count:" << sp1.use_count() << endl;  //统计sp1管理的内存由几个指针共同管理。
    return 0;
}