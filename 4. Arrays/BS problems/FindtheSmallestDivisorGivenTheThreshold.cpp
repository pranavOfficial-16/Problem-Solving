#include <bits/stdc++.h>
using namespace std;
bool possible(vector<int> &nums, int divisor, int threshold)
{
    int n = nums.size();
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += ceil((double)nums[i] / (double)divisor);
        if (sum > threshold)
            return false;
    }
    return sum <= threshold;
}
int smallestDivisor(vector<int> &nums, int threshold)
{
    int n = nums.size();
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
        maxi = max(maxi, nums[i]);
    int low = 1, high = maxi;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (possible(nums, mid, threshold))
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}