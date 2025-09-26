#include <iostream>
#include <vector>
// #include <ranges>    ranges需要C++20版本
using namespace std;
int main()
{
    vector<int> v = {1, 2, 3, 4, 5};
    return 0;
}

/*  以下是ranges的用法
for(int x:v | std::ranges::views::filter([](int n){return n%2==0}) |
    std::ranges::views::transform([](int n){return n*n;})  |
    std::ranges::views::drop(2) |
    std::ranges::views::take(3) |
    std::ranges::views::reverse
    )
    cout << x ;    //筛选出偶数,取平方，去前两个，再取前3个，逆序输出

for(int x:std::ranges::views::iota(1,6))
    cout << x;   //迭代器产生递增数列1~6

vector<vector<int>> vv={1,{2,3},{4,5,6}}
for(int x:vv | std::ranges::views::join)  //join,将数据展开。
    cout << x;
    */