#include <bits/stdc++.h>
using namespace std;
void findCombination(int index, int target, vector<int> &candidates,
                     vector<int> &ds, vector<vector<int>> &ans)
{
    // base case
    if (index == candidates.size())
    {
        if (target == 0)
            ans.push_back(ds);
        return;
    }

    // pick the element
    if (candidates[index] <= target)
    {
        ds.push_back(candidates[index]);
        findCombination(index, target - candidates[index], candidates, ds, ans);
        ds.pop_back(); // backtrack
    }

    // not pick the element
    findCombination(index + 1, target, candidates, ds, ans);
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> ds;
    findCombination(0, target, candidates, ds, ans);
    return ans;
}