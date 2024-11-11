#include <bits/stdc++.h>
using namespace std;

/*
    Bruteforce
        TC -> O(n^2)
        SC -> O(1)
*/
int longestOnes(vector<int> &nums, int k)
{
    int zeros, maxlen = 0, n = nums.size();
    for (int i = 0; i < n; i++)
    {
        zeros = 0;
        for (int j = i; j < n; j++)
        {
            if (nums[i] == 0)
                zeros++;
            if (zeros <= k)
                maxlen = max(maxlen, j - i + 1);
            else
                break;
        }
    }
    return maxlen;
}

/*
    better
        TC -> O(2n)
        SC -> O(1)
*/
int longestOnes(vector<int> &nums, int k)
{
    int l = 0, r = 0, zeros = 0, maxlen = 0, n = nums.size();
    while (r < n)
    {
        if (nums[r] == 0)
            zeros++;
        if (zeros <= k)
            maxlen = max(maxlen, r - l + 1);
        while (zeros > k)
        {
            if (nums[l] == 0)
                zeros--;
            l++;
        }
        r++;
    }
    return maxlen;
}

/*
    Optimal
        TC -> O(n)
        SC -> O(1)
*/
int longestOnes(vector<int> &nums, int k)
{
    int l = 0, r = 0, zeros = 0, maxlen = 0, n = nums.size();
    while (r < n)
    {
        if (nums[r] == 0)
            zeros++;
        if (zeros <= k)
            maxlen = max(maxlen, r - l + 1);
        else
        {
            if (nums[l] == 0)
                zeros--;
            l++;
        }
        r++;
    }
    return maxlen;
}