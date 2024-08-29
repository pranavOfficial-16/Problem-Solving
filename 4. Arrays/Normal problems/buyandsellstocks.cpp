#include <bits/stdc++.h>
using namespace std;
int stocks(int arr[], int n)
{
    int buy = 0, sell = 1, profit = 0, maxprofit = 0;
    while (sell < n)
    {
        if (arr[buy] < arr[sell])
        {
            profit = arr[sell] - arr[buy];
            maxprofit = max(profit, maxprofit);
        }
        else
            buy = sell;
        sell++;
    }
    return maxprofit;
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << stocks(arr, n) << endl;
    return 0;
}
