#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int main()
{
    vector<int> v = {6, 2, 7, 3, 9, 1, 5, 78};

    auto it = find(v.begin(), v.end(), 5); // find�������ص����������û�в��ҵ�����end
    if (it != v.end())
        cout << "Founded " << *it << endl;

    auto it2 = find_if(v.begin(), v.end(), [](int x)
                       { return x > 70; });
    if (it2 != v.end())
        cout << "Found first num which greater than 70 : " << *it2 << endl;

    if (all_of(v.begin(), v.end(), [](int x) // ���Ƶ�,����none_of,any_of,����bool��.
               { return x > 0; }))
        cout << "All elements are greater than zero." << endl;

    sort(v.begin(), v.end()); // Ĭ����������
    for (int x : v)
    {
        cout << x << ' ';
    }
    cout << endl;

    sort(v.begin(), v.end(), [](int x, int y) // ��lambda����д��������
         { return x > y; });
    for (int x : v)
    {
        cout << x << ' ';
    }
    cout << endl;

    sort(v.begin(), v.end(), std::greater<int>()); // ��STL����д�������С�
    for (int x : v)
    {
        cout << x << ' ';
    }
    cout << endl;

    int sum = accumulate(v.begin(), v.end(), 0); // Ĭ�ϼӷ����㣬init=0��
    cout << "Sum of v: " << sum << endl;

    int res = accumulate(v.begin(), v.end(), 1, multiplies<int>()); // ����Ϊ�˷����㣬init=1
    cout << "Res of v: " << res << endl;

    return 0;
}