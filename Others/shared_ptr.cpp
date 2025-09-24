#include <iostream>
#include <memory>
using namespace std;

struct B; // 前向声明，只能利用其指针。

struct A
{
    // shared_ptr<B> ptr_B;
    weak_ptr<B> ptr_B; // weak指针只观察，不增加引用次数。
    ~A()
    {
        cout << "A destroyed." << endl;
    }
};

struct B
{
    shared_ptr<A> ptr_A;
    ~B()
    {
        cout << "B destroyed." << endl;
    }
};

int main()
{
    auto p1 = make_shared<A>();
    auto p2 = make_shared<B>();
    p1->ptr_B = p2;
    p2->ptr_A = p1; // 离开main函数作用域时候，若采用shared_ptr指针，A,B的管理计数由2减到1，不为0.堆上A，B的内存不会被释放，造成内存泄露事故。

    auto p3 = make_shared<int>(35);
    weak_ptr<int> p4 = p3;
    cout << "Use count:" << p3.use_count() << endl;
    if (auto temp = p4.lock())
    {
        cout << "p4 points at:" << *temp << endl;
    } // 临时从观察指针p4中获取一个shared指针，在当前作用域内(即此个if循环内)有效。
    p3.reset(); // 销毁p3.
    if (auto temp = p4.lock())
    { // 此时p3对应的引用次数是0，被我们手动reset了，p4.lock()返回空指针nullptr.
        cout << "p4 points at:" << *temp << endl;
    }
    else
    {
        cout << "Destroyed." << endl;
    }

    return 0;
}
// weak指针的常用用法是打破循环引用的问题。
// 最常用的用法是，父对象持有子对象，用shared_ptr; 子对象持有父对象，用weak_ptr;
