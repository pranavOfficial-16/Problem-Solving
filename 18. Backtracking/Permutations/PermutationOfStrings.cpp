// No of permutations -> n!
#include <bits/stdc++.h>
using namespace std;
void solve(string s, vector<string> &ans, int index)
{
    // base case
    if (index == s.size())
    {
        ans.push_back(s);
        return;
    }

    for (int i = index; i < s.size(); i++)
    {
        swap(s[index], s[i]);
        solve(s, ans, index + 1);
        swap(s[index], s[i]); // backtrack
    }
}
vector<string> permute(string s)
{
    vector<string> ans;
    int index = 0;
    solve(s, ans, index);
    return ans;
}
int main()
{
    string s;
    cin >> s;
    vector<string> ans = permute(s);
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