#include <iostream>
#include <vector>
using namespace std;

class Student
{
private:
    string name;
    float score;
    static int count; // 对象的变量，一般用构造函数初始化；静态变量，在外部初始化。

public:
    Student(string n, float s) // 构造函数，在定义时被调用。
    {
        name = n;
        score = s;
        cout << "Creat for " << name << endl;
        count++;
    }
    void ChangeInfo(string name, float score)
    {
        this->name = name;
        this->score = score; // 等号左边是对象的变量，右边是传入函数的参数。通常this是可以省去的，但是当变量名冲突时就需要指明了。
    }
    void PrintInfo()
    {
        cout << name << ',' << score << endl;
    }
    static void PrintCount()
    {
        cout << "Total Number: " << count << endl;
        // cout << name << score << endl;  这句话是不被允许的。除非传入一个参数 Student& stu，那就可以通过类函数的参数来指定操作的对象了。
    }

    ~Student() // 析构函数，在销毁时被调用。定义在栈上时，按照退栈顺序（LIFO）;
    {
        cout << "Ending for " << name << endl;
    }
};

int Student::count = 0; // 静态变量的初始化，需要在类外，Main函数前
int main()
{

    Student stu1("Bithery", 78.5);
    Student stu2("Kerrina", 74.9);              // stu1,stu2都是定义在栈(Stack)上的。
    Student *stu3 = new Student("Batty", 65.2); // 在堆上创建属于Student类的对象stu3.
    Student::PrintCount();
    stu3->PrintInfo(); // 指针调用
    cout << "Now delete stu3." << endl;
    delete stu3;
    cout << "Main Function Over." << endl;
    return 0;
}

// Summary:
// Static Variety 在类中只是声明，必须在类外，main前再去定义，分配空间并初始化。
// Static的变量与函数是作用于整个类，所有成员共享。
// Static函数只能访问Static变量，不能访问类的变量。
// 可以用对象去访问类的变量与方法，但不推荐，更推荐的方法是通过类来访问，如：
// Student::count(如果是public)，Student::Printcount().

// this指针是属于成员函数的，指向被调用的对象。
// 因此，静态函数没有this指针，是无法去访问，调用成员变量和成员函数的，如果需要，我们要人为往函数里面传入一个对象。

// public,可以在类外访问； private,只能在类内访问; protected,可以在类内及其继承的派生类访问，不能在类外访问。