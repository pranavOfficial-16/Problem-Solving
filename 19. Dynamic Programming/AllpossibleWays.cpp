#include<bits/stdc++.h>
using namespace std;

// dp
int helper(int x, int n, int curNo, int *dp)
{
    if (x < 0)
    {
        return 0;
    }
    if (x == 0)
    {
        return 1;
    }

    int ans = 0;

    for (int i = curNo; pow(i, n) <= x; i++)
    {
        ans += helper(x - pow(i, n), n, i + 1, dp);
    }
    dp[x] = ans;
    return ans;
}
int allWays(int x, int n)
{
    int dp[100000];
    for (int i = 0; i < 100000; i++)
    {
        dp[i] = -1;
    }
    return helper(x, n, 1, dp);
}

int main()
{
    return 0;
}