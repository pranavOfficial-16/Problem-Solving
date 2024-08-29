#include <bits/stdc++.h>
using namespace std;
int subarraysXor(vector<int> &arr, int x)
{
    int n = arr.size();
    unordered_map<int, int> mpp;
    mpp[0]++;
    int sum = 0, count = 0;
    for (int i = 0; i < n; i++)
    {
        sum ^= arr[i];
        if (mpp.find(sum ^ x) != mpp.end())
            count += mpp[sum ^ x];
        mpp[sum]++;
    }
    return count;
}