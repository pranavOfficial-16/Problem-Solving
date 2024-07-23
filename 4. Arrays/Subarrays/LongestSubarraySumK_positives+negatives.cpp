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
        // check if sum matches the key
        if (sum == k)
            maxlen = max(maxlen, i + 1);
        int rem = sum - k;
        // check if the rem is in the map
        if (mp.find(rem) != mp.end())
        {
            int len = i - mp[rem];
            maxlen = max(maxlen, len);
        }
        // if the rem is not in the map
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