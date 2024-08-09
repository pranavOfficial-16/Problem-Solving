#include <bits/stdc++.h>
using namespace std;
int missingNumber(int arr[], int n)
{
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]] = 1;
    }
    for (int i = 0; i <= n; i++)
    {
        if (mpp[i] != 1)
            return i;
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << missingNumber(arr, n);
    return 0;
}