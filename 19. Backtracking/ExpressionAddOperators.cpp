#include <bits/stdc++.h>
using namespace std;
void solve(string s, int target, vector<string> &ans, int index,
           string path, long eval, long residual)
{
    // base case
    if (index == s.length())
    {
        if (eval == target)
        {
            ans.push_back(path);
            return;
        }
    }
    string currStr;
    long num = 0;
    for (int j = index; j < s.length(); j++)
    {
        // handle 0
        if (j > index && s[index] == '0')
            return;
        currStr += s[j];
        num = num * 10 + s[j] - '0';
        if (index == 0)
            solve(s, target, ans, j + 1, path + currStr, num, num);
        else
        {
            solve(s, target, ans, j + 1, path + "+" + currStr, eval + num, num);
            solve(s, target, ans, j + 1, path + "-" + currStr, eval - num, -num);
            solve(s, target, ans, j + 1, path + "*" + currStr,
                  eval - residual + residual * num, residual * num);
        }
    }
}
vector<string> addOperators(string s, int target)
{
    vector<string> ans;
    solve(s, target, ans, 0, "", 0, 0);
    return ans;
}