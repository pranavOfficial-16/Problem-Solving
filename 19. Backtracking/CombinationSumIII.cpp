#include <bits/stdc++.h>
using namespace std;
void findCombinations(int index, vector<int> &nums, int k, int n,
                      vector<int> &ds, vector<vector<int>> &ans)
{
    // base case
    if (index == nums.size())
    {
        if (ds.size() == k && n == 0)
            ans.push_back(ds);
        return;
    }

    // pick the element
    if (nums[index] <= n)
    {
        ds.push_back(nums[index]);
        findCombinations(index + 1, nums, k, n - nums[index], ds, ans);
        ds.pop_back(); // backtrack
    }

    // not pick the element
    findCombinations(index + 1, nums, k, n, ds, ans);
}
vector<vector<int>> combinationSum3(int k, int n)
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    vector<vector<int>> ans;
    vector<int> ds;
    findCombinations(0, nums, k, n, ds, ans);
    return ans;
}