#include <bits/stdc++.h>
using namespace std;
// dp
int minCount(int n)
{
    int *ans = new int[n + 1];
    ans[0] = 0;
    ans[1] = 1;
    ans[2] = 2;
    ans[3] = 3;

    for (int i = 4; i <= n; i++)
    {
        ans[i] = i;
        for (int j = 1; j <= ceil(sqrt(n)); j++)
        {
            int temp = j * j;
            if (temp > i)
                break;
            else
                ans[i] = min(ans[i], 1 + ans[i - temp]);
        }
    }
    return ans[n];
}
int main()
{
    int n;
    cin >> n;
    cout << minCount(n);
    return 0;
}