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
    // 无参数的默认构造函数

    Animal(int age) // 这个构造函数不会被子类继承，但可以被调用写子类的继承函数。
    {
        this->age = age;
    }
    virtual void eat() // Virtual表明这个函数可以在子类中被重写
    {
        cout << "I can eat." << endl;
    }
    void sleep() // 该函数可以被子类继承重写，但不能被调用。
    {
        cout << "I can sleep." << endl;
    }
};

class Dog : public Animal
{
public:
    Dog(int age) : Animal(age) {}; // 先调用父类的构造函数。同时可以看出age是可以在子类Dog中访问的，子类也具有这个属性。
                                   // 又由于我们是通过调用父类构造函数来初始化age，因此即使它是private也可以正常初始化。

    void bark()
    {
        cout << "I can bark" << endl;
    }
    void PrintAge()
    {
        cout << "I'm " << age << " years old!" << endl; // 如果age是private属性，则不能直接访问，需要在父类写一个GetAge()函数，通过调用父类方法来获取。
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

// 1.创建子类对象时，调用子类的构建函数前必须先调用父类的构造函数
// 2.子类继承了父类的所有属性和方法，但有一些是不能继承的，他们是
// *构造函数  *析构函数 *赋值运算符 *友元函数