#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int a, b, c;
    cout << "Input your numbers." << endl;
    cin >> a >> b >> c;
    int sum = a + b + c;
    double avg = sum / 3.0;
    cout << "��=" << sum << endl;
    cout << "ƽ��ֵ=" << fixed << setprecision(2) << avg << endl;
    return 0;
}