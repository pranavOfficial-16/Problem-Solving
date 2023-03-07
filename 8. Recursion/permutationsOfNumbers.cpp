// Total no of permutations - n!

// Method-1 - using backtracking  ( return permutation of numbers )
// #include <bits/stdc++.h>
// using namespace std;
// void solve(vector<int> nums, vector<vector<int>> &ans, int index)
// {
//     // base case
//     if (index >= nums.size())
//     {
//         ans.push_back(nums);
//         return;
//     }
//     // Permutations made
//     for (int i = index; i < nums.size(); i++)
//     {
//         swap(nums[index], nums[i]);
//         solve(nums, ans, index + 1);
//         // backtrack
//         swap(nums[index], nums[i]);
//     }
// }
// vector<vector<int>> permute(vector<int> &nums)
// {
//     vector<vector<int>> ans;
//     int index = 0;
//     solve(nums, ans, index);
//     return ans;
// }
// int main()
// {
//     int n;
//     cin >> n;
//     vector<int> nums;
//     int a;
//     for (int i = 0; i < n; i++)
//     {
//         cin >> a;
//         nums.push_back(a);
//     }
//     vector<vector<int>> v = permute(nums);
//     for (vector<int> i : v)
//     {
//         for (int j : i)
//             cout << j;
//         cout << endl;
//     }
//     return 0;
// }

// Method-2 - using backtracking  ( print all the permutation of numbers )
#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> nums, vector<vector<int>> &ans, int index)
{
    // base case
    if (index >= nums.size())
    {
        ans.push_back(nums);
        return;
    }
    // Permutations made
    for (int i = index; i < nums.size(); i++)
    {
        swap(nums[index], nums[i]);
        solve(nums, ans, index + 1);
        // backtrack
        swap(nums[index], nums[i]);
    }
}
void permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    int index = 0;
    solve(nums, ans, index);
    for (vector<int> i : ans)
    {
        for (int j : i)
            cout << j;
        cout << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> nums;
    int a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        nums.push_back(a);
    }
    permute(nums);
    return 0;
}