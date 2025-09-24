// ��������ѧϰC++�е�һ����Ҫ���� vector
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    //--------1.��ʼ��-----------//
    vector<int> a;              // ���Ը��������ʼ���������û�еĻ���Ĭ��Ϊ�գ�push_back��ʱ���Զ�����
    vector<int> b(5, 10);       // b�а���5����ʼֵΪ10��int�����ݡ�
    vector<int> c{2, 5, 9, 11}; // ���б�ķ�ʽ��ʼ����
    //--------2.��������------//
    cout << "Initial Size of a:" << a.size() << endl;
    a.push_back(10);
    a.push_back(20);
    cout << "Size of a after push_back:" << a.size() << endl;
    cout << "First Element Of a: " << a[0] << endl;
    cout << "First Element Of c: " << c.front() << endl;
    cout << "Second Element of c: " << c.at(1) << endl;
    cout << "Last Element of c: " << c.back() << endl;
    b.pop_back();
    cout << "The Capacity Of b:" << b.capacity() << endl;
    cout << "Size of b:" << b.size() << endl;

    //---------3.������������ɾ��--------//
    c.insert(c.begin() + 2, 99);       // ���±�2λ�ã����Ԫ��99. ����.begin()/.end()���ص��ǵ���������
    c.erase(c.begin() + 3);            // ɾ���±�3��Ԫ��
    for (int i = 0; i < c.size(); i++) // ��ͳC��д����
        cout << c[i] << ' ';
    cout << endl;
    for (int x : c) // ������д��
        cout << x << ' ';
    cout << endl;
    //---------4. �����÷�---------//
    b.clear(); // clear��size������capacity
    cout << b.empty() << endl;
    a.swap(c); // ����vector
    for (int x : a)
        cout << x << ' ';
    cout << endl;
    a.resize(6, 8); // ��Ϊ6��size��������Ĳ�8.
    for (int x : a)
        cout << x << ' ';
    cout << endl;
    int *p = a.data(); //.data()ȡ��vector a��ָ�룬ʹ�������ָ��p��ͳC����������
    return 0;
}