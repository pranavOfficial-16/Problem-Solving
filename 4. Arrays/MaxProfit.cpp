#include<bits/stdc++.h>
using namespace std;
int maximumProfit(int arr[], int n)
{
    int profit = INT_MIN;
    int price = 0;
    sort(arr, arr + n);
    for (int i = 0; i < n; i++)
    {
        int count = (n - i);
        // Updating the maximum profit
        if (profit < count * arr[i])
        {
            price = arr[i];
            profit = count * arr[i];
        }
    }
    return profit;
}

int main()
{
    int n, *input, i, *cost;
    cin >> n;
    input = new int[n];
    for (i = 0; i < n; i++)
        cin >> input[i];

    cout << maximumProfit(input, n) << endl;
}
