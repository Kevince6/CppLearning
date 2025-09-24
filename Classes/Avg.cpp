#include <iostream>
#include <vector>
using namespace std;

class Student
{
private:
    string name;
    double score;
    static int count;

public:
    Student(string name, double score)
    {
        this->name = name;
        this->score = score;
        count++;
    }
    double GetScore() const // const表示，该函数不能够修改this指针对应的各变量值。
    {
        return score;
    }
    static double AvgScore(const vector<Student> &students) // 这里const表示，被引用(&)的参数不能在该函数里被修改。
    {
        double sum = 0.0;
        for (const auto &s : students) // 表示取出可迭代对象students中的每一项s，自动推测其类型，在for内不对s作修改，用的是&表示不是拷贝值。
            sum += s.GetScore();       // s的类型是const Student，在调用Student类方法时，只能调用const方法。
        double avg = sum / count;
        return avg;
    }
};

int Student::count = 0;

int main()
{
    vector<Student> students = {
        {"Cathy", 85.5},
        {"Mia", 93.5},
        {"Jonhson", 76}};
    double avg = Student::AvgScore(students);
    cout << avg << endl;
    return 0;
}
