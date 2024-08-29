#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<char, int> &a, pair<char, int> &b)
{
    return a.second > b.second;
}
int main()
{
    map<char, int> mpp;

    string s = "cccaaa";
    for (int i = 0; i < s.size(); i++)
        mpp[s[i]]++;

    cout << mpp.size();

    return 0;
}