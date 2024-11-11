#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> nums, vector<int> output, int index,
           vector<vector<int>> &ans)
{
    // base case
    if (index == nums.size())
    {
        ans.push_back(output);
        return;
    }

    // skip duplicates
    int nextIndex = index + 1;
    while (nextIndex < nums.size() && nums[nextIndex] == nums[index])
        nextIndex++;

    // exclude
    solve(nums, output, nextIndex, ans);

    // include
    int element = nums[index];
    output.push_back(element);
    solve(nums, output, index + 1, ans);
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> output;
    int index = 0;
    sort(nums.begin(), nums.end());
    solve(nums, output, index, ans);
    return ans;
}