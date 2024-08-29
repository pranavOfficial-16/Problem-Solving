#include <bits/stdc++.h>
using namespace std;
string removeOuterParentheses(string s)
{
    int open_count = 0, close_count = 0;
    int start = 0;
    string ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
            open_count++;
        else if (s[i] == ')')
            close_count++;

        if (open_count == close_count)
        {
            ans += s.substr(start + 1, i - start - 1);
            start = i + 1;
        }
    }
    return ans;
}