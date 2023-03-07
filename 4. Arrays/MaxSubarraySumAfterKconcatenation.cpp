// Maximum subarray sum after K concatenation
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t; // no of test case
    cin >> t;
    while (t > 0)
    {
        int n;    // size of vector
        int k;    // no of times the concat should happen
        int temp; // to accept input
        cin >> n;
        cin >> k;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            cin >> temp;
            v.push_back(temp);
        }
        vector<int> c;
        for (int i = 0; i < k; i++)
        {
            c.insert(c.begin(), v.begin(), v.end());
        }
        // vector to array
        int si = c.size();
        int *arr = new int[si];
        for (int i = 0; i < si; i++)
        {
            arr[i] = c[i];
        }
        int mx = INT_MIN;
        int sum = 0;
        for (int i = 0; i < si; i++)
        {
            sum += arr[i];
            mx = max(mx, sum);
            if (sum < 0)
                sum = 0;
        }
        cout << mx << endl;
        t--;
    }
    return 0;
}