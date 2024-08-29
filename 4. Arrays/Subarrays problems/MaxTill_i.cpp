#include <bits/stdc++.h>
using namespace std;
void maxTill_i(int arr[], int n)
{
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
        cout << maxi << " ";
    }
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    maxTill_i(arr, n);
    return 0;
}