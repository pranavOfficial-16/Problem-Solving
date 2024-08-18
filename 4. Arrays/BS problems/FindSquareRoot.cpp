#include <bits/stdc++.h>
using namespace std;
long long int floorSqrt(long long int n)
{
    long long low = 1;
    long long high = n;
    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        if (mid * mid <= n)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return high;
}