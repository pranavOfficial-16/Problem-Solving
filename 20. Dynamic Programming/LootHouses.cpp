#include <bits/stdc++.h>
using namespace std;

// bruteforce
int maxMoneyLooted(int *arr, int n)
{
    if (n == 0)
        return 0;

    int x = maxMoneyLooted(arr + 2, n - 2) + arr[0];
    int y = maxMoneyLooted(arr + 1, n - 1);

    return max(x, y);
}

// dp
int getmaxmoney(int arr[], int n, int *dp)
{
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);

    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]);
    }
    return dp[n - 1];
}
int getMaxMoney(int arr[], int n)
{
    int *dp = new int[n];
    return getmaxmoney(arr, n, dp);
}

int main()
{
    return 0;
}