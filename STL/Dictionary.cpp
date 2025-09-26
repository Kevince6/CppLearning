#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

void Calculation(string s, string tofind, map<string, int> &counter)
{
    string T = tofind;
    transform(s.begin(), s.end(), s.begin(), [](unsigned char c) // 转为小写。
              { return tolower(c); });
    transform(tofind.begin(), tofind.end(), tofind.begin(), [](unsigned char c) // 转为小写。
              { return tolower(c); });
    size_t pos = s.find(tofind);
    while (pos != std::string::npos)
    {
        counter[T]++;
        s = s.substr(pos + tofind.size(), s.size() - pos - tofind.size());
        pos = s.find(tofind);
    }
}

int main()
{
    string sentence = "I like the apple.The apple is the most nutrient one among varieties of food.";
    map<string, int> counter;
    Calculation(sentence, "apple", counter);
    Calculation(sentence, "The", counter);
    for (auto &x : counter)
    {
        cout << x.first << ':' << x.second << endl;
    }

    return 0;
}