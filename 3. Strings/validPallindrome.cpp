#include <bits/stdc++.h>
using namespace std;
string lower(string &s)
{
    // convert to lower case
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
            s[i] += 32;
    }
    return s;
}
string remove(string s)
{
    // remove ,
    string output;
    for (int i = 0; i < s.size(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9'))
            output += s[i];
    }
    return output;
}
bool isPalindrome(string s)
{
    string str = lower(s);
    string output = remove(str);
    int n = output.size();
    for (int i = 0; i < n; i++)
    {
        if (output[i] != output[n - i - 1])
            return false;
    }
    return true;
}
int main()
{
    string s;
    getline(cin, s);
    if (isPalindrome(s))
        cout << "true";
    else
        cout << "false";
    return 0;
}