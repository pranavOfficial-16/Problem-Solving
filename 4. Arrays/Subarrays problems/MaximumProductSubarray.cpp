#include <bits/stdc++.h>
using namespace std;
int maxProductSubArray(vector<int> &nums)
{
    int n = nums.size();
    int prefix = 1, suffix = 1;
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (prefix == 0)
            prefix = 1;
        if (suffix == 0)
            suffix = 1;
        prefix = prefix * nums[i];
        suffix = suffix * nums[n - i - 1];
        maxi = max(maxi, max(prefix, suffix));
    }
    return maxi;
}

int main()
{
    vector<int> nums = {1, 2, -3, 0, -4, -5};
    cout << "The maximum product subarray: " << maxProductSubArray(nums);
    return 0;
}
