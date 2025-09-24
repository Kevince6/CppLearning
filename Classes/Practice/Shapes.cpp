#include <iostream>
#define PI 3.14
using namespace std;

class Shape
{
protected:
    double S;

public:
    virtual double area()
    {
        return S;
    }
};

class Rectangle : public Shape
{
private:
    double a;
    double b;

public:
    Rectangle(double a, double b) : a(a), b(b) {};
    double area() override
    {
        S = a * b;
        return S;
    }
};

class Circle : public Shape
{
private:
    double r;

public:
    Circle(double r) : r(r) {};
    double area() override
    {
        S = r * r * PI;
        return S;
    }
};

int main()
{
    Rectangle a(2.5, 3.5);
    Circle b(3);
    cout << a.area() << endl;
    cout << b.area() << endl;
    return 0;
}