#include <bits/stdc++.h>
using namespace std;
bool comp(pair<int, int> a, pair<int, int> b)
{
    double r1 = (double)a.first / a.second;
    double r2 = (double)b.first / b.second;
    return r1 > r2;
}
double fractionalKnapsack(vector<int> &val, vector<int> &wt, int capacity)
{
    vector<pair<int, int>> arr;

    for (int i = 0; i < val.size(); ++i)
        arr.emplace_back(val[i], wt[i]);

    sort(arr.begin(), arr.end(), comp);

    double totalval = 0;

    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i].second <= capacity)
        {
            totalval += arr[i].first;
            capacity = capacity - arr[i].second;
        }
        else
        {
            totalval += ((double)arr[i].first / arr[i].second) * capacity;
            break;
        }
    }
    return totalval;
}