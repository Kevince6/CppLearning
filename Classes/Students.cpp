#include <iostream>
#include <vector>
using namespace std;

class Student
{
private:
    string name;
    float score;
    static int count; // ����ı�����һ���ù��캯����ʼ������̬���������ⲿ��ʼ����

public:
    Student(string n, float s) // ���캯�����ڶ���ʱ�����á�
    {
        name = n;
        score = s;
        cout << "Creat for " << name << endl;
        count++;
    }
    void ChangeInfo(string name, float score)
    {
        this->name = name;
        this->score = score; // �Ⱥ�����Ƕ���ı������ұ��Ǵ��뺯���Ĳ�����ͨ��this�ǿ���ʡȥ�ģ����ǵ���������ͻʱ����Ҫָ���ˡ�
    }
    void PrintInfo()
    {
        cout << name << ',' << score << endl;
    }
    static void PrintCount()
    {
        cout << "Total Number: " << count << endl;
        // cout << name << score << endl;  ��仰�ǲ�������ġ����Ǵ���һ������ Student& stu���ǾͿ���ͨ���ຯ���Ĳ�����ָ�������Ķ����ˡ�
    }

    ~Student() // ����������������ʱ�����á�������ջ��ʱ��������ջ˳��LIFO��;
    {
        cout << "Ending for " << name << endl;
    }
};

int Student::count = 0; // ��̬�����ĳ�ʼ������Ҫ�����⣬Main����ǰ
int main()
{

    Student stu1("Bithery", 78.5);
    Student stu2("Kerrina", 74.9);              // stu1,stu2���Ƕ�����ջ(Stack)�ϵġ�
    Student *stu3 = new Student("Batty", 65.2); // �ڶ��ϴ�������Student��Ķ���stu3.
    Student::PrintCount();
    stu3->PrintInfo(); // ָ�����
    cout << "Now delete stu3." << endl;
    delete stu3;
    cout << "Main Function Over." << endl;
    return 0;
}

// Summary:
// Static Variety ������ֻ�����������������⣬mainǰ��ȥ���壬����ռ䲢��ʼ����
// Static�ı����뺯���������������࣬���г�Ա����
// Static����ֻ�ܷ���Static���������ܷ�����ı�����
// �����ö���ȥ������ı����뷽���������Ƽ������Ƽ��ķ�����ͨ���������ʣ��磺
// Student::count(�����public)��Student::Printcount().

// thisָ�������ڳ�Ա�����ģ�ָ�򱻵��õĶ���
// ��ˣ���̬����û��thisָ�룬���޷�ȥ���ʣ����ó�Ա�����ͳ�Ա�����ģ������Ҫ������Ҫ��Ϊ���������洫��һ������

// public,������������ʣ� private,ֻ�������ڷ���; protected,���������ڼ���̳е���������ʣ�������������ʡ�