// 异常机制throw,catch,try的配合使用,异常类可以被继承
#include <iostream>
using namespace std;
int divide(int a, int b)
{
    if (b == 0)
    {
        throw runtime_error("Divide by zero!"); // throw抛出异常
    }
    return a / b;
}

class MyErr : public exception
{
public:
    const char *what() const noexcept override
    { // 自定义异常类，重写what()方法，noexcept gurantee no exceptions would occur in this function.
        return "My custom error.";
    }
};
int main()
{
    try
    {
        cout << divide(6, 2) << endl;
        cout << divide(10, 0) << endl;
    }
    catch (const exception &e)
    {                                                     // catch捕捉最近的异常,一般用exception就可以了
        cout << "Caught exception: " << e.what() << endl; // 用what方法获得e中捕获的被throw抛出的错误信息
    }
    cout << "Program Continues ..." << endl;

    try
    {
        throw runtime_error("Time Excess.");
    }
    catch (MyErr &e)
    {
        cout << "Caught my exception: " << e.what() << endl;
    }
    return 0;
}