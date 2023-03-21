#include <bits/stdc++.h>
using namespace std;
int solve(int n, vector<int> &ans)
{
    if (n == 0 || n == 1)
        return n;

    // Check if output already exists
    if (ans[n] != -1)
        return ans[n];

    // Calculate output
    int a = solve(n - 1, ans);
    int b = solve(n - 2, ans);

    // Save the output for future use
    ans[n] = a + b;

    // Return the final output
    return ans[n];
}
int fibo(int n)
{
    vector<int> ans(n + 1, -1);
    return solve(n, ans);
}
int main()
{
    int n;
    cin >> n;
    cout << fibo(n) << endl;
}