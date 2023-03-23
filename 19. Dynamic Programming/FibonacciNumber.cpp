#include <bits/stdc++.h>
using namespace std;

// Brute force approach -> TC - 2^n
int solve1(int n)
{
    if (n == 0 || n == 1)
        return n;
    return solve1(n - 1) + solve1(n - 2);
}

// Memoization -> ( Top-down approach ) ( Recursive ) TC - O(n)
int solve2(int n, vector<int> &ans)
{
    if (n == 0 || n == 1)
        return n;

    // Check if output already exists
    if (ans[n] != -1)
        return ans[n];

    // Calculate output
    int a = solve2(n - 1, ans);
    int b = solve2(n - 2, ans);

    // Save the output for future use
    ans[n] = a + b;

    // Return the final output
    return ans[n];
}
int fibo(int n)
{
    vector<int> ans(n + 1, -1);
    return solve2(n, ans);
}

// Dynamic programming -> ( Bottom-up approach) ( Iterative ) TC - O(n)
int solve3(int n)
{
    int *ans = new int[n + 1];

    ans[0] = 0;
    ans[1] = 1;

    for (int i = 2; i <= n; i++)
        ans[i] = ans[i - 1] + ans[i - 2];

    return ans[n];
}

int main()
{
    int n;
    cin >> n;
    cout << solve3(n) << endl;
}