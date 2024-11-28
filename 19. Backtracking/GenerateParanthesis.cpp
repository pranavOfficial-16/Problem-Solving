#include <bits/stdc++.h>
using namespace std;
void solve(int open, int close, string output, int n, vector<string> &res)
{
    // base case
    if (open == close && open + close == n * 2)
    {
        res.push_back(output);
        return;
    }

    if (open < n)
        solve(open + 1, close, output + "(", n, res);

    if (close < open)
        solve(open, close + 1, output + ")", n, res);
}
vector<string> generateParenthesis(int n)
{
    vector<string> res;
    solve(0, 0, "", n, res);
    return res;
}