// 本节练习目的是训练掌握string类常见的几类方法。
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    string name = "Dictionary";
    //------1.简单查询操作-----------//
    cout << "-----1.查询操作------" << endl;
    cout << "Size:" << name.size() << endl;
    cout << "长度" << name.length() << endl;
    cout << "是否为空" << name.empty() << endl;
    cout << "第一个字符" << name.front() << endl;
    cout << "最后一个字符:" << name.back() << endl;
    cout << "第三个字符:" << name[2] << endl;
    cout << "第五个字符:" << name.at(4) << endl;

    //------2.添加与删除----------//
    cout << "-------2.添加与删除------" << endl;
    string suffix = "ies";
    name += suffix;
    name.append(" apple");
    name.push_back('!');
    cout << "修改后的name:" << name << endl;
    name.pop_back();
    cout << "修改后的name:" << name << endl;

    //-----3.查找与替换------//
    cout << "--------3.查找与替换--------" << endl;
    size_t pos = name.find("apple");
    size_t rpos = name.rfind("apple");
    if (pos != string::npos && rpos != string::npos)
    {
        cout << "Apple locates in:" << pos << endl;
        cout << "Apple locates in:" << rpos << endl;
    }

    name.replace(pos, 5, "Banana");
    cout << "name aft replacement:" << name << endl;

    //------4.提取，比较与转换-----//
    cout << "------4.提取,比较与转换------" << endl;
    string sub = name.substr(pos, 6);
    cout << "Substracted String:" << sub << endl;
    cout << "Comparation btw name & sub:" << name.compare(sub) << endl;

    //-----5.清除------//
    cout << "-----5.清除------" << endl;
    name.clear();
    cout << name << endl;

    return 0;
}