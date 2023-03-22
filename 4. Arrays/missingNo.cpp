#include <bits/stdc++.h>
using namespace std;
int missingNumber(int arr[], int n)
{
    int num = n * (n + 1) / 2;
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return num - sum;
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