#include <bits/stdc++.h>
using namespace std;
bool checksequenece(string s1, string s2)
{
    // base case
    if (s1.empty() && s2.empty())
        return true;
    if (s1.empty())
        return false;
    if (s2.empty())
        return true;
    if (s1[0] == s2[0])
        return checksequenece(s1.substr(1), s2.substr(1));
    else
        return checksequenece(s1.substr(1), s2);
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    bool x = checksequenece(s1, s2);
    if (x)
        cout << "true";
    else
        cout << "false";
}