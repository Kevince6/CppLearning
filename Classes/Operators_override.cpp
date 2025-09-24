#include <iostream>
#include <vector>
using namespace std;

class Vector2
{
private:
    int x;
    int y;

public:
    Vector2(int x = 0, int y = 0) : x(x), y(y) {} // ����һ����ʼ����䣬���蹹�캯���Ϳ��Գ�ʼ�����ʺ������const��Ա�����ó�Ա��
    Vector2 operator+(const Vector2 &other)
    { // Ҫϰ��const &�Ĳ�������ģʽ��
        return Vector2(x + other.x, y + other.y);
    }
    void PrintVector()
    {
        cout << '(' << x << ',' << y << ')' << endl;
    }
    friend ostream &operator<<(ostream &os, const Vector2 v); // �����ڶ�<<��������һ��˵�������������������ostream����Ҫһ������ostream&
};

ostream &operator<<(ostream &os, const Vector2 v)
{
    return os << '(' << v.x << ',' << v.y << ')' << endl;
}

int main()
{
    Vector2 a(1, 2);
    Vector2 b(3, 4);
    Vector2 c = a + b;
    c.PrintVector();   // ͨ���������ڷ��������c.
    cout << c << endl; // ͨ������������<<�����������c.
    return 0;
}

// 1.��������ؿ����ǳ�Ա������Ҳ������ȫ�ֺ���(��ʱ�������������һ�߲����������)
// 2.�����Ŀ������ص��������:+ - * / % == [] () << >>
// 3.��Ԫ����friend. ������˵�����⺯���ǲ��ܷ���private��Ա�ģ����ǵ����ò�����ʱ���Ϳ��Զ�����Ԫ������