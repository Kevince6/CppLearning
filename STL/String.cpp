// ������ϰĿ����ѵ������string�ೣ���ļ��෽����
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string name = "Dictionary";
    //------1.�򵥲�ѯ����-----------//
    cout << "-----1.��ѯ����------" << endl;
    cout << "Size:" << name.size() << endl;
    cout << "����" << name.length() << endl;
    cout << "�Ƿ�Ϊ��" << name.empty() << endl;
    cout << "��һ���ַ�" << name.front() << endl;
    cout << "���һ���ַ�:" << name.back() << endl;
    cout << "�������ַ�:" << name[2] << endl;
    cout << "������ַ�:" << name.at(4) << endl;

    //------2.�����ɾ��----------//
    cout << "-------2.�����ɾ��------" << endl;
    string suffix = "ies";
    name += suffix;
    name.append(" apple");
    name.push_back('!');
    cout << "�޸ĺ��name:" << name << endl;
    name.pop_back();
    cout << "�޸ĺ��name:" << name << endl;

    //-----3.�������滻------//
    cout << "--------3.�������滻--------" << endl;
    size_t pos = name.find("apple");
    size_t rpos = name.rfind("apple");
    if (pos != string::npos && rpos != string::npos)
    {
        cout << "Apple locates in:" << pos << endl;
        cout << "Apple locates in:" << rpos << endl;
    }

    name.replace(pos, 5, "Banana");
    cout << "name aft replacement:" << name << endl;

    //------4.��ȡ���Ƚ���ת��-----//
    cout << "------4.��ȡ,�Ƚ���ת��------" << endl;
    string sub = name.substr(pos, 6);
    cout << "Substracted String:" << sub << endl;
    cout << "Comparation btw name & sub:" << name.compare(sub) << endl;

    //-----5.���------//
    cout << "-----5.���------" << endl;
    name.clear();
    cout << name << endl;

    return 0;
}