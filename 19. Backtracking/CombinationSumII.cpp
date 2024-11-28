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
        findCombination(index + 1, target - candidates[index], candidates, ds, ans);
        ds.pop_back(); // backtrack
    }

    // Skip duplicates
    int nextIndex = index + 1;
    while (nextIndex < candidates.size() && candidates[nextIndex] == candidates[index])
        nextIndex++;

    // not pick the element
    findCombination(nextIndex, target, candidates, ds, ans);
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> ds;
    sort(candidates.begin(), candidates.end());
    findCombination(0, target, candidates, ds, ans);
    return ans;
}