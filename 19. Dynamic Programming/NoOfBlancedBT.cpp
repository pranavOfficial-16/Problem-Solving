#include <bits/stdc++.h>
using namespace std;
// bruteforce
int balancedBTs(int h)
{
    if (h <= 1)
        return 1;

    int x = balancedBTs(h - 1);
    int y = balancedBTs(h - 2);
    int mod = (int)(pow(10, 9) + 7);

    int temp1 = (int)(((long)(x)*x) % mod);
    int temp2 = (int)((2 * (long)(x)*y) % mod);

    int ans = (temp1 + temp2) % mod;

    return ans;
}

// dp
int binaryTreesOfHeightH(int h)
{

    int *dp = new int[h + 1];

    dp[0] = 1;
    dp[1] = 1;

    int mod = (int)(pow(10, 9) + 7);
    for (int i = 2; i <= h; i++)
    {
        dp[i] = (int)(((long)(dp[i - 1]) * dp[i - 1]) % mod + (2 * (long)(dp[i - 1]) * dp[i - 2]) % mod) % mod;
    }

    return dp[h];
}
int main()
{
    int h;
    cin >> h;
    cout << binaryTreesOfHeightH(h);
    return 0;
}