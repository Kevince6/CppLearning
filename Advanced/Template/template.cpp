// ����ѧϰģ���뷺����������
#include <iostream>
#include <vector>
using namespace std;

namespace MyMath
{
    template <typename T> // ָ��һ��������T�����ú���ʱ������������Զ��ƶϲ�������
    T max(T a, T b)       // ���ݷ�����Tд��һ��ģ�庯��
    {
        return a > b ? a : b;
    }

    template <> // �Ժ�����ϸ��
    int max<int>(int a, int b)
    {
        cout << "Specialization for int type." << endl;
        return a > b ? a : b;
    }

    template <typename T1, typename T2>
    auto add(T1 a, T2 b) -> decltype(a + b)
    {                 // decltype��ȡ�������ͣ��������ڷ������з������͵��Ƶ���
        return a + b; // ��ȻC++14�ı�׼���棬�ǿ��Բ�дdecltype�Ƶ�ʽ�ģ����������Զ��Ƶ���
    }

}

template <typename S = int> // �÷�����S�������ģ�壬��������.���Ը�S����Ĭ�ϲ�����
class MyBox
{
private:
    S val;

public:
    MyBox(S val) : val(val) {}
    S Get_box() { return val; }
};

template <>
class MyBox<string>
{
private:
    string val;

public:
    MyBox(string line) : val(line) {}
    string Get_box()
    {
        cout << "Specialization for string." << endl; // ����ģ���ϸ����
        return val;
    }
};

template <typename S>
using mb = MyBox<S>; // ��mb��Ϊģ��MyBox�ı���.using��templateһ���ã������typename����Ҫ����Ҫ�С�ֻ�ܶ���ģ��using��������

int main()
{
    cout << MyMath::max(5, 2) << endl;
    cout << MyMath::max(1.6, 3.14) << endl;
    cout << MyMath::max('a', 'x') << endl;
    cout << MyMath::add(3, 6.8) << endl;
    mb<int> box1(92);
    MyBox<string> box2("Saikeng");
    cout << box1.Get_box() << endl;
    cout << box2.Get_box() << endl;
    return 0;
}