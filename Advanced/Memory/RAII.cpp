// RAII(��Դ��ȡ��ʼ��),��C++����Ҫ���ԡ������Զ������ص㣬��ʵ���ǹ��캯�������������󶨶�������ʹ�ö�����������������Զ��ͷ�
// C++�е�����ָ��(�Զ��ڴ����)���ļ�����������RAII˼�������
#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>
using namespace std;
class RAII
{
private:
    int *ptr;

public:
    RAII(int val) : ptr(new int(val))
    {
        cout << "Resource Acquired." << endl;
    };
    ~RAII()
    {
        delete ptr;
        cout << "Resource released." << endl;
    }
    int get()
    {
        return *ptr;
    }
}; // �����һ��RAII˼���ָ�룬Ҳ���Կ���һ���Լ�ʵ�ֵļ򵥵�����ָ�롣

int main()
{

    RAII ptr(5);
    cout << ptr.get() << endl; // �Զ��ڴ����

    {
        ifstream file("../texts/plan.txt"); // ����ʱ�Զ����ļ�
        string line;
        if (file.is_open())
        {
            getline(file, line); // ���ļ��л�ȡ
            cout << line << endl;
        }
    } // �뿪�������ʱ���Զ��ر��ļ�������Ҫfile.fclose()

    return 0;
}