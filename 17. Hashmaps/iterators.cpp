#include <bits/stdc++.h>
using namespace std;
int main()
{
    unordered_map<string, int> ourmap;
    ourmap["abc"] = 1;
    ourmap["abc1"] = 2;
    ourmap["abc2"] = 3;
    ourmap["abc3"] = 4;
    ourmap["abc4"] = 5;
    ourmap["abc5"] = 6;

    // The auto keyword automatically detects the data type of a variable by its initialization.
    for (auto i = ourmap.begin(); i != ourmap.end(); i++)
        cout << "Key : " << i->first << " Value: " << i->second << endl;

    // find
    unordered_map<string, int>::iterator it2 = ourmap.find("abc");

    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    for (auto i = v.begin(); i != v.end(); i++)
        cout << *i << endl;
}
