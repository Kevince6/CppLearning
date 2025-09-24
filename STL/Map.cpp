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
    mp["Laura"] = 83;         // 添加键值对
    mp.insert({"Urine", 59}); // 通过方法添加键值对
    mp.erase("Cathy");
    cout << "Size of mp:" << mp.size() << endl;
    cout << "Empty or not:" << mp.empty() << endl;
    if (mp.find("Yorym") != mp.end())
        cout << "Find Yorym which score:" << mp["Yorym"] << endl;
    for (auto &x : mp) // map的遍历
        cout << x.first << ":" << x.second << endl;
    cout << mp.count("Alice") << endl;
    return 0;
}

// 储存键值对，默认按key升序排序。
// key:value的实际类型是 std::pair<const key,value>.

// Map是基于红黑树实现的，它是有序的；而unordered_map是基于Hash实现的，它是无序的。
// 使用基本方法两者相同，但基于Hash的无序map会更快。