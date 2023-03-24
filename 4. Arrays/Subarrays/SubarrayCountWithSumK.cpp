#include <bits/stdc++.h>
using namespace std;

// bruteforce -> O(n^2)
int solve(int arr[], int n, int k)
{
    int sum, count = 0;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            if (sum == k)
                count++;
        }
    }
    return count;
}

// optimal -> O(n)
int solve1(vector<int> &arr, int k)
{
    int n = arr.size();
    unordered_map<int, int> mpp;
    int count = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == k)
            count++;
        if (mpp.find(sum - k) != mpp.end())
            count += mpp[sum - k];
        mpp[sum]++;
    }
    return count;
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