#include <bits/stdc++.h>
using namespace std;
// optimal
int solve(int arr[], int n, int k)
{
    map<int, int> mp;
    int sum = 0;
    int maxlen = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == k)
            maxlen = max(maxlen, i + 1);
        int rem = sum - k;
        if (mp.find(rem) != mp.end())
        {
            int len = i - mp[rem];
            maxlen = max(maxlen, len);
        }
        if (mp.find(sum) == mp.end())
            mp[sum] = i;
    }
    return maxlen;
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int k;
    cin >> k;
    cout << solve(arr, n, k);
    return 0;
}