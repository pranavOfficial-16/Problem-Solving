#include <bits/stdc++.h>
using namespace std;

/*
    Bruteforce
        TC -> O(n^2)
        SC -> O(1)
*/
int numSubarraysWithSum(vector<int> &nums, int goal)
{
    int sum, count = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += nums[j];
            if (sum == goal)
                count++;
            if (sum > goal)
                break;
        }
    }
    return count;
}

/*
    Optimal
        TC -> O(2 * 2n)
        SC -> O(1)
*/
int solve(vector<int> &nums, int goal)
{
    // edge case
    if (goal < 0)
        return 0;

    int l = 0, r = 0, count = 0, sum = 0;
    int n = nums.size();

    while (r < n)
    {
        sum += nums[r];
        while (sum > goal)
        {
            sum -= nums[l];
            l++;
        }
        count += (r - l + 1);
        r++;
    }
    return count;
}
int numSubarraysWithSum1(vector<int> &nums, int goal)
{
    return solve(nums, goal) - solve(nums, goal - 1);
}
int main(){
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    int goal;
    cin >> goal;
    cout << numSubarraysWithSum1(nums, goal);
}