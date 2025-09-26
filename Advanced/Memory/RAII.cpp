// RAII(资源获取初始化),是C++的重要特性。具有自动化的特点，其实就是构造函数和析构函数绑定对象，这样使得对象跟随其生命周期自动释放
// C++中的智能指针(自动内存管理)，文件流，锁都是RAII思想的体现
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
}; // 这就是一个RAII思想的指针，也可以看作一个自己实现的简单的智能指针。

int main()
{

    RAII ptr(5);
    cout << ptr.get() << endl; // 自动内存管理

    {
        ifstream file("../texts/plan.txt"); // 构造时自动打开文件
        string line;
        if (file.is_open())
        {
            getline(file, line); // 从文件中获取
            cout << line << endl;
        }
    } // 离开作用域的时候自动关闭文件，不需要file.fclose()

    return 0;
}