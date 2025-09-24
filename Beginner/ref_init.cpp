#include <iostream>
using namespace std;

int main()
{
    int a = 10;
    int &r = a;
    r = 20;
    cout << r << endl;
    return 0;

    // This is a test
}