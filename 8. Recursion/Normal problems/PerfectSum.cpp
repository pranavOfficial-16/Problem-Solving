#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
void solve(vector<int> &nums, int index, int currentSum, int &count, int k)
{
    // Base case
    if (index == nums.size())
    {
        if (currentSum == k)
            count++;
        return;
    }

    // Exclude
    solve(nums, index + 1, currentSum, count, k);

    // Include
    solve(nums, index + 1, currentSum + nums[index], count, k);
}
int perfectSum(int arr[], int n, int k)
{
    vector<int> nums(arr, arr + n);
    int count = 0;
    solve(nums, 0, 0, count, k);
    return count % mod;
}