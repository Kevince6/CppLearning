#include <iostream>
#include <vector>
using namespace std;

void printStr(string &&s)
{ // 作右值引用，该函数在调用右值字面量的时候是直接移动而不是复制，可以提高程序效率
    cout << "Rvalue reference:" << s << endl;
}

int main()
{
    vector<int> v1 = {1, 2, 3, 4, 5};
    vector<int> v2 = move(v1);
    printStr("World.");
    cout << v1.size() << ' ' << v2.size() << endl;
    return 0;
}