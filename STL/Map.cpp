#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<string, int> mp = {
        {"Alice", 65},
        {"Cathy", 73},
        {"Yorym", 92},
    };
    mp["Laura"] = 83;         // ��Ӽ�ֵ��
    mp.insert({"Urine", 59}); // ͨ��������Ӽ�ֵ��
    mp.erase("Cathy");
    cout << "Size of mp:" << mp.size() << endl;
    cout << "Empty or not:" << mp.empty() << endl;
    if (mp.find("Yorym") != mp.end())
        cout << "Find Yorym which score:" << mp["Yorym"] << endl;
    for (auto &x : mp) // map�ı���
        cout << x.first << ":" << x.second << endl;
    cout << mp.count("Alice") << endl;
    return 0;
}

// �����ֵ�ԣ�Ĭ�ϰ�key��������
// key:value��ʵ�������� std::pair<const key,value>.

// Map�ǻ��ں����ʵ�ֵģ���������ģ���unordered_map�ǻ���Hashʵ�ֵģ���������ġ�
// ʹ�û�������������ͬ��������Hash������map����졣