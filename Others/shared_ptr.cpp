#include <iostream>
#include <memory>
using namespace std;

struct B; // ǰ��������ֻ��������ָ�롣

struct A
{
    // shared_ptr<B> ptr_B;
    weak_ptr<B> ptr_B; // weakָ��ֻ�۲죬���������ô�����
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
    p2->ptr_A = p1; // �뿪main����������ʱ��������shared_ptrָ�룬A,B�Ĺ��������2����1����Ϊ0.����A��B���ڴ治�ᱻ�ͷţ�����ڴ�й¶�¹ʡ�

    auto p3 = make_shared<int>(35);
    weak_ptr<int> p4 = p3;
    cout << "Use count:" << p3.use_count() << endl;
    if (auto temp = p4.lock())
    {
        cout << "p4 points at:" << *temp << endl;
    } // ��ʱ�ӹ۲�ָ��p4�л�ȡһ��sharedָ�룬�ڵ�ǰ��������(���˸�ifѭ����)��Ч��
    p3.reset(); // ����p3.
    if (auto temp = p4.lock())
    { // ��ʱp3��Ӧ�����ô�����0���������ֶ�reset�ˣ�p4.lock()���ؿ�ָ��nullptr.
        cout << "p4 points at:" << *temp << endl;
    }
    else
    {
        cout << "Destroyed." << endl;
    }

    return 0;
}
// weakָ��ĳ����÷��Ǵ���ѭ�����õ����⡣
// ��õ��÷��ǣ�����������Ӷ�����shared_ptr; �Ӷ�����и�������weak_ptr;
