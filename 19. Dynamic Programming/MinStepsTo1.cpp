#include <bits/stdc++.h>
using namespace std;

// Brute force
int countMinStepsToOne(int n)
{
    if (n == 1)
        return 0;

    int x = countMinStepsToOne(n - 1);
    int y = INT_MAX, z = INT_MAX;
    if (n % 2 == 0)
        y = countMinStepsToOne(n / 2);
    if (n % 3 == 0)
        z = countMinStepsToOne(n / 3);

    int ans = min(x, min(y, z)) + 1;
    return ans;
}

// Memoization
int minStepsHelper(int n, int *ans)
{
    if (n == 1)
        return 0;

    if (ans[n] != -1)
        return ans[n];

    int x = minStepsHelper(n - 1, ans);
    int y = INT_MAX, z = INT_MAX;
    if (n % 2 == 0)
        y = minStepsHelper(n / 2, ans);
    if (n % 3 == 0)
        z = minStepsHelper(n / 3, ans);
    int output = min(x, min(y, z)) + 1;

    ans[n] = output;
    return output;
}
int minSteps(int n)
{
    int *ans = new int[n + 1];

    for (int i = 0; i <= n; i++)
        ans[i] = -1;

    return minStepsHelper(n, ans);
}

// DP
int minSteps1(int n)
{
    int *ans = new int[n + 1];
    ans[1] = 0;
    int x, y;
    for (int i = 2; i <= n; i++)
    {
        x = INT_MAX, y = INT_MAX;
        if (i % 2 == 0)
            x = ans[i / 2];
        if (i % 3 == 0)
            y = ans[i / 3];
        ans[i] = 1 + min(ans[i - 1], min(x, y));
    }
    return ans[n];
}
int main()
{
    int n;
    cin >> n;
    cout << minSteps1(n);
    return 0;
}