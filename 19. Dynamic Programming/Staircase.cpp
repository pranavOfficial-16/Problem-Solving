#include <bits/stdc++.h>
using namespace std;
// bruteforce
int countSteps(int n)
{
    if (n == 0)
        return 1;
    if (n < 0)
        return 0;
    return countSteps(n - 1) + countSteps(n - 2) + countSteps(n - 3);
}

// Dp
int countSteps1(int n)
{
    int *ans = new int[n + 1];
    ans[0] = 1;
    ans[1] = 1;
    ans[2] = 2;
    for (int i = 3; i <= n; i++)
        ans[i] = ans[i - 1] + ans[i - 2] + ans[i - 3];
    return ans[n];
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << countSteps1(n) << endl;
    }
    return 0;
}