#include <iostream>
#include <iomanip>
namespace Math
{
    int add(int x = 0, int y = 0)
    {
        return x + y;
    }
    double add(double x = 0.0, double y = 0.0)
    {
        return x + y;
    }
    double add(int x = 0, double y = 0.0)
    {
        return x + y;
    }
}

int main()
{
    int x = 8, y = 5;
    double a = 6.2389, b = 3.1415;
    int sum_xy = Math::add(x, y);
    double sum_ab = Math::add(a, b);
    double sum_ax = Math::add(x, a);
    std::cout << std::fixed << std::setprecision(2) << sum_xy << ' ' << sum_ab << ' ' << sum_ax << std::endl;
    return 0;
}