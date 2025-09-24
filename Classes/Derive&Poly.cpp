#include <iostream>
#include <vector>
using namespace std;

class Animal
{
protected:
    int age;

public:
    /*Animal()
    {
        age = 0;
    } */
    // �޲�����Ĭ�Ϲ��캯��

    Animal(int age) // ������캯�����ᱻ����̳У������Ա�����д����ļ̳к�����
    {
        this->age = age;
    }
    virtual void eat() // Virtual����������������������б���д
    {
        cout << "I can eat." << endl;
    }
    void sleep() // �ú������Ա�����̳���д�������ܱ����á�
    {
        cout << "I can sleep." << endl;
    }
};

class Dog : public Animal
{
public:
    Dog(int age) : Animal(age) {}; // �ȵ��ø���Ĺ��캯����ͬʱ���Կ���age�ǿ���������Dog�з��ʵģ�����Ҳ����������ԡ�
                                   // ������������ͨ�����ø��๹�캯������ʼ��age����˼�ʹ����privateҲ����������ʼ����

    void bark()
    {
        cout << "I can bark" << endl;
    }
    void PrintAge()
    {
        cout << "I'm " << age << " years old!" << endl; // ���age��private���ԣ�����ֱ�ӷ��ʣ���Ҫ�ڸ���дһ��GetAge()������ͨ�����ø��෽������ȡ��
    }
    void eat() override
    {
        cout << "I can eat MEAT!" << endl;
    }
};

int main()
{
    Animal ani(8);
    Dog dog(5);
    dog.bark();
    dog.PrintAge();
    ani.eat();
    dog.eat();
    return 0;
}

// 1.�����������ʱ����������Ĺ�������ǰ�����ȵ��ø���Ĺ��캯��
// 2.����̳��˸�����������Ժͷ���������һЩ�ǲ��ܼ̳еģ�������
// *���캯��  *�������� *��ֵ����� *��Ԫ����