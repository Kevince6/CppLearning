// �쳣����throw,catch,try�����ʹ��,�쳣����Ա��̳�
#include <iostream>
using namespace std;
int divide(int a, int b)
{
    if (b == 0)
    {
        throw runtime_error("Divide by zero!"); // throw�׳��쳣
    }
    return a / b;
}

class MyErr : public exception
{
public:
    const char *what() const noexcept override
    { // �Զ����쳣�࣬��дwhat()������noexcept gurantee no exceptions would occur in this function.
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
    {                                                     // catch��׽������쳣,һ����exception�Ϳ�����
        cout << "Caught exception: " << e.what() << endl; // ��what�������e�в���ı�throw�׳��Ĵ�����Ϣ
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