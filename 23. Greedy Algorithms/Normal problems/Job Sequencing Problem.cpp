#include <bits/stdc++.h>
using namespace std;
struct Jobs
{
    int id, deadline, profit;
};
static bool comp(Jobs val1, Jobs val2)
{
    return val1.profit > val2.profit;
}
vector<int> JobSequencing(vector<int> &id, vector<int> &deadline, vector<int> &profit)
{
    int n = profit.size();
    int count = 0, totalProfit = 0, maxDeadline = 0;

    vector<Jobs> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i].id = id[i];
        arr[i].deadline = deadline[i];
        arr[i].profit = profit[i];
    }

    sort(arr.begin(), arr.end(), comp);

    for (int i = 0; i < n; i++)
    {
        maxDeadline = max(maxDeadline, arr[i].deadline);
    }
    vector<int> hash(maxDeadline + 1, -1);

    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].deadline; j >= 1; j--)
        {
            if (hash[j] == -1)
            {
                count++;
                hash[j] = arr[i].id;
                totalProfit += arr[i].profit;
                break;
            }
        }
    }
    return {count, totalProfit};
}