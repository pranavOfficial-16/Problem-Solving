#include <bits/stdc++.h>
using namespace std;
// bruteforce -> TC - O(n^3)
void solve(int arr[], int n)
{
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += arr[k];
            }
            maxi = max(maxi, sum);
        }
    }
    cout << maxi;
}

// better -> TC - O(n^2)
void solve1(int arr[], int n)
{
    int sum, maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            maxi = max(maxi, sum);
        }
    }
    cout << maxi;
}

// kadane's algorithm -> TC - O(n)
void solve2(int arr[], int n)
{
    int sum = 0;
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum < 0)
            sum = 0;
        maxi = max(maxi, sum);
    }
    cout << maxi;
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    solve2(arr, n);
    return 0;
}