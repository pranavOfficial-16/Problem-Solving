#include <bits/stdc++.h>
using namespace std;
int possible(vector<int> &nums, int sumsplit)
{
    int n = nums.size();
    int cnt = 1, sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum + nums[i] > sumsplit)
        {
            cnt++;
            sum = nums[i];
        }
        else
            sum += nums[i];
    }
    return cnt;
}
int splitArray(vector<int> &nums, int k)
{
    int n = nums.size();
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int cnt = possible(nums, mid);
        if (cnt <= k)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}