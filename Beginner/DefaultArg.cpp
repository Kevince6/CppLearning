// ����ѧϰCpp�еĺ���������Ĭ�ϲ���
#include <iostream>
using namespace std;

void greet(string name = "Guest", string msg = "Welcome")
{
    cout << msg << ',' << name << '!' << endl;
}

void aputs(int x, int y = 0)
{
    cout << x << ',' << y << endl;
}

int main()
{
    greet();
    string name = "Oliver";
    string msg = "Fku";
    int x = 78;
    greet(name);
    greet(msg);
    greet(name, msg);
    aputs(x);
    return 0;
}

// Overloading��Default Arguement����ͬʱʹ�ã�����Ҫע������Ե����⡣
// �磺 void(int x=0)  ��  void() �Ƕ���ģ� �������ᱨ��