#include <bits/stdc++.h>
using namespace std;
void solve(string s, string output, int index, vector<string> &ans)
{
    // base case
    if (index == s.size())
    {
        if (output.size() > 0)
            ans.push_back(output);
        return;
    }

    // exclude
    solve(s, output, index + 1, ans);

    // include
    char element = s[index];
    output.push_back(element);
    solve(s, output, index + 1, ans);
}
vector<string> subsequences(string s)
{
    vector<string> ans;
    string output;
    int index = 0;
    solve(s, output, index, ans);
    return ans;
}
int main()
{
    string s;
    cin >> s;
    vector<string> ans = subsequences(s);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j];
        }
        cout << endl;
    }
    return 0;
}