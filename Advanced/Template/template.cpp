// 本节学习模板与泛编程相关内容
#include <iostream>
#include <vector>
using namespace std;

namespace MyMath
{
    template <typename T> // 指定一个泛类型T，调用函数时根据输入参数自动推断参数类型
    T max(T a, T b)       // 根据泛类型T写的一个模板函数
    {
        return a > b ? a : b;
    }

    template <> // 对函数的细化
    int max<int>(int a, int b)
    {
        cout << "Specialization for int type." << endl;
        return a > b ? a : b;
    }

    template <typename T1, typename T2>
    auto add(T1 a, T2 b) -> decltype(a + b)
    {                 // decltype获取对象类型，经常用于泛函数中返回类型的推导。
        return a + b; // 当然C++14的标准里面，是可以不写decltype推导式的，编译器会自动推导。
    }

}

template <typename S = int> // 用泛类型S定义的类模板，即泛型类.可以给S定义默认参数。
class MyBox
{
private:
    S val;

public:
    MyBox(S val) : val(val) {}
    S Get_box() { return val; }
};

template <>
class MyBox<string>
{
private:
    string val;

public:
    MyBox(string line) : val(line) {}
    string Get_box()
    {
        cout << "Specialization for string." << endl; // 对类模板的细化。
        return val;
    }
};

template <typename S>
using mb = MyBox<S>; // 让mb作为模板MyBox的别名.using和template一起用，里面的typename不重要，但要有。只能对类模板using重命名。

int main()
{
    cout << MyMath::max(5, 2) << endl;
    cout << MyMath::max(1.6, 3.14) << endl;
    cout << MyMath::max('a', 'x') << endl;
    cout << MyMath::add(3, 6.8) << endl;
    mb<int> box1(92);
    MyBox<string> box2("Saikeng");
    cout << box1.Get_box() << endl;
    cout << box2.Get_box() << endl;
    return 0;
}