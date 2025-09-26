#include <iostream>
#include <vector>
using namespace std;
/*
    ... Args      ����һ��ģ�������
    Args ... args  ���庯��������
    args ...  ʹ�ò�����ʱ��չ��
    args + ...   C++17����,��˼���üӺŽ����в�����������.*/

template <typename... Args> // C++17 �۵����ʽд��
auto sum(Args... args)
{
    return (... + args);
}

template <typename T>
T Mysum(T val)
{
    return val;
}

template <typename T, typename... Rest>
T Mysum(T first, Rest... rests)
{
    return first + Mysum(rests...);
}

int main()
{
    auto s1 = sum(1, 7, 2.5, 0);
    auto s2 = sum(1, 7, 2.5, 0);
    cout << s1 << endl
         << s2 << endl;
    return 0;
}