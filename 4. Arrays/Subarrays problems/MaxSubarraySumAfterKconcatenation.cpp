// Maximum subarray sum after K concatenation
#include <bits/stdc++.h>
using namespace std;
void solve(vector<int> v, int n, int k)
{
    // copying the array k times
    vector<int> ans;
    for (int i = 0; i < k; i++)
        ans.insert(ans.begin(), v.begin(), v.end());

    // kadane's algo
    int mx = INT_MIN;
    int sum = 0;
    for (int i = 0; i < ans.size(); i++)
    {
        sum += ans[i];
        mx = max(mx, sum);
        if (sum < 0)
            sum = 0;
    }
    cout << mx << endl;
}
int main()
{
    int n;
    int k;
    int temp;
    cin >> n;
    cin >> k;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        v.push_back(temp);
    }
    solve(v, n, k);
    return 0;
}