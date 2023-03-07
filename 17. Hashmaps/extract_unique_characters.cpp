#include <bits/stdc++.h>
using namespace std;
string uniqueChar(string str)
{
    unordered_map<char, bool> map;
    string s;
    for (int i = 0; i < str.size(); i++)
    {
        if (map.count(str[i]) > 0)
            continue;
        map[str[i]] = true;
        s += str[i];
    }
    return s;
}
int main()
{
    string str;
    cin>>str;
    cout << uniqueChar(str);
    return 0;
}