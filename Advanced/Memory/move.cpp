#include <iostream>
#include <vector>
using namespace std;

void printStr(string &&s)
{ // ����ֵ���ã��ú����ڵ�����ֵ��������ʱ����ֱ���ƶ������Ǹ��ƣ�������߳���Ч��
    cout << "Rvalue reference:" << s << endl;
}

int main()
{
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = move(v1);
    printStr("World.");
    cout << v1.size() << ' ' << v2.size() << endl;
    return 0;
}