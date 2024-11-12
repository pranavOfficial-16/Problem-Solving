#include <bits/stdc++.h>
using namespace std;

/*
    Optimal
        TC -> O(n)
        SC -> O(k)
*/
int solve(vector<int> &nums, int k)
{
    // edge case
    if (k < 0)
        return 0;

    int n = nums.size();
    unordered_map<int, int> distelements;
    int l = 0, r = 0, count = 0;
    while (r < n)
    {
        distelements[nums[r]]++;
        while (distelements.size() > k)
        {
            distelements[nums[l]]--;
            if (distelements[nums[l]] == 0)
                distelements.erase(nums[l]);
            l++;
        }
        count += (r - l + 1);
        r++;
    }
    return count;
}
int subarraysWithKDistinct(vector<int> &nums, int k)
{
    return solve(nums, k) - solve(nums, k - 1);
}