#include <bits/stdc++.h>
using namespace std;
bool possible(vector<int> &bloomDay, int day, int m, int k)
{
    long long cnt = 0, nob = 0;
    for (int i = 0; i < bloomDay.size(); i++)
    {
        if (bloomDay[i] <= day)
            cnt++;
        else
        {
            nob += (cnt / k);
            cnt = 0;
        }
    }
    nob += (cnt / k);
    return nob >= m;
}
int minDays(vector<int> &bloomDay, int m, int k)
{
    if ((long)m * k > bloomDay.size())
        return -1;
    int mini = INT_MAX, maxi = INT_MIN;
    for (int i = 0; i < bloomDay.size(); i++)
    {
        mini = min(mini, bloomDay[i]);
        maxi = max(maxi, bloomDay[i]);
    }
    int low = mini, high = maxi;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (possible(bloomDay, mid, m, k))
        {
            // if true
            high = mid - 1;
        }
        else
        {
            // if false
            low = mid + 1;
        }
    }
    return low;
}