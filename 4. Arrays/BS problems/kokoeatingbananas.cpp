#include <bits/stdc++.h>
using namespace std;
long long solve(vector<int> &piles, int hourly)
{
    long long totaltime = 0;
    for (int i = 0; i < piles.size(); i++)
    {
        totaltime += ceil((double)(piles[i]) / (double)(hourly));
    }
    return totaltime;
}
int minEatingSpeed(vector<int> &piles, int h)
{
    int low = 1;
    int maxi = INT_MIN;
    for (int i = 0; i < piles.size(); i++)
        maxi = max(maxi, piles[i]);
    int high = maxi;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        long long reqhour = solve(piles, mid);
        if (reqhour <= h)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}