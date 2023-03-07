// Total no of permutations - n!

// Method-1 - using backtracking  ( return permutation of strings )
// #include <bits/stdc++.h>
// using namespace std;
// void solve(string str, int index, vector<string>& ans)
// {
//     // base case
//     if (index >= str.size())
//     {
//         ans.push_back(str);
//         return;
//     }
//     // Permutations made
//     for (int i = index; i < str.size(); i++)
//     {
//         swap(str[index], str[i]);
//         solve(str,index + 1,ans);
//         // backtrack
//         swap(str[index], str[i]);
//     }
// }
// vector<string> permute(string &str)
// {
//     int index = 0;
//     vector<string> ans;
//     solve(str,index,ans);
//     return ans;
// }
// int main()
// {
//     string str;
//     cin >> str;
//     vector<string> ans = permute(str);
//     for(string s : ans)
//         cout<<s<<endl;
//     return 0;
// }

// Method-2 - using backtracking  ( print all the permutation of strings )
#include <bits/stdc++.h>
using namespace std;
void solve(string str, int index, vector<string> &ans)
{
    // base case
    if (index >= str.size())
    {
        ans.push_back(str);
        return;
    }
    // Permutations made
    for (int i = index; i < str.size(); i++)
    {
        swap(str[index], str[i]);
        solve(str, index + 1, ans);
        // backtrack
        swap(str[index], str[i]);
    }
}
void permute(string &str)
{
    int index = 0;
    vector<string> ans;
    solve(str, index, ans);
    for (string s : ans)
        cout << s << endl;
}
int main()
{
    string str;
    cin >> str;
    permute(str);
    return 0;
}