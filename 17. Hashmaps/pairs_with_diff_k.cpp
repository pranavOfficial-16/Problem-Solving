#include <bits/stdc++.h>
using namespace std;
int getPairsWithDifferenceK(int *arr, int n, int k)
{
    int count = 0;
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        int temp = arr[i] + k;
        count += map[temp];
        if (k != 0)
        {
            temp = arr[i] - k;
            count += map[temp];
        }
        map[arr[i]]++;
    }
    return count;
}