// ���ڽ�������ָ���ʹ�á��������ָͨ�룬����ָ���Զ��ڴ��������delete
// һ�����������͵�����ָ�룬ÿ��ָ����ʹ�õ�ʱ����һЩ�涨��
// ������ unique_ptr shared_ptr weak_ptr
#include <iostream>
#include <memory>
using namespace std;
int main()
{
    unique_ptr<int> p1(new int(10));
    unique_ptr<int> p2 = make_unique<int>(5);
    cout << *p1 << ' ' << *p2 << endl;
    // p2 = p1;  unique_ptr<int> q3 = p1; �ⶼ�ǲ�������ġ�unique_ptr���ɿ���
    p2 = move(p1); // ����uniqueָ������ƶ��������ʾp2��Ϊ����p1ָ����ڴ棬p1��Ϊnullptr.
    cout << *p2 << endl;
    if (p1 == nullptr)
        cout << "p1 points at NULL after move operation." << endl;

    shared_ptr<int> sp1 = make_shared<int>(28);
    shared_ptr<int> sp2 = sp1;
    cout << *sp1 << ' ' << *sp2 << endl;
    cout << "Use count:" << sp1.use_count() << endl;  //ͳ��sp1������ڴ��ɼ���ָ�빲ͬ����
    return 0;
}