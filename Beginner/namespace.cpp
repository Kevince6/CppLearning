// 本节是有关命名空间的简单练习
#include <iostream>
using namespace std;
namespace SpaceA
{
    int value = 23;
    void greet()
    {
        std::cout << "Good Morning!" << std::endl;
    }
}

void greet()
{
    std::cout << "Good Afternoon!" << std::endl;
}

int main()
{
    cout << SpaceA::value << endl;
    SpaceA::greet();
    greet();
    return 0;
}

// 从这里可以看出，当同一个函数名在不同的命名空间中出现时，若使用using namespace，则有可能产生歧义。
// 因此在实际工程中，会尽量避免使用using namespace。
