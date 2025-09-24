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
    double GetScore() const // const��ʾ���ú������ܹ��޸�thisָ���Ӧ�ĸ�����ֵ��
    {
        return score;
    }
    static double AvgScore(const vector<Student> &students) // ����const��ʾ��������(&)�Ĳ��������ڸú����ﱻ�޸ġ�
    {
        double sum = 0.0;
        for (const auto &s : students) // ��ʾȡ���ɵ�������students�е�ÿһ��s���Զ��Ʋ������ͣ���for�ڲ���s���޸ģ��õ���&��ʾ���ǿ���ֵ��
            sum += s.GetScore();       // s��������const Student���ڵ���Student�෽��ʱ��ֻ�ܵ���const������
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
