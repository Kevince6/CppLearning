#include <iostream>
#include <vector>
using namespace std;

template <typename T>
using Vec = vector<T>;

template <typename... Args> // �����ö�Ӧ��������ж������ͣ�����<int double string>
class MyCounter
{
public:
    void printSize()
    {
        cout << sizeof...(Args) << endl; // ���۵����ʽ��
    }
};

template <typename... Args> // ������࣬�յ�tupple
class MyTuple;

template <typename First, typename... Rest> // �ػ��࣬������һ������
class MyTuple<First, Rest...>
{
public:
    First head;
    MyTuple<Rest...> tail;
    MyTuple(First head, Rest... rests) : head(head), tail(rests...) {};
};

template <typename Last> // �ݹ�����࣬���һ��Ԫ��,���ػ�(���⴦��)
class MyTuple<Last>
{
public:
    Last head;
    MyTuple(Last head) : head(head) {};
};

int main()
{
    MyCounter<int, double, float, string, vector<int>, Vec<string>> mct;
    MyTuple<int, double, string> mtp(12, 3.14, "Cherry");
    mct.printSize();
    cout << mtp.head << mtp.tail.head << mtp.tail.tail.head << endl;
    return 0;
}
