// �������й������ռ�ļ���ϰ
#include <iostream>
using namespace std;
namespace SpaceA
{
    int value = 23;
    void greet()
    {
        std::cout << "Good Morning!" << std::endl;
    }
}

void greet()
{
    std::cout << "Good Afternoon!" << std::endl;
}

int main()
{
    cout << SpaceA::value << endl;
    SpaceA::greet();
    greet();
    return 0;
}

// ��������Կ�������ͬһ���������ڲ�ͬ�������ռ��г���ʱ����ʹ��using namespace�����п��ܲ������塣
// �����ʵ�ʹ����У��ᾡ������ʹ��using namespace��
