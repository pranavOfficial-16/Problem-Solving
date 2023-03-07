#include <bits/stdc++.h>
using namespace std;
int highestFrequency(int arr[], int n)
{
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
        map[arr[i]]++;
    int key = 0;
    int value = 0;
    for (int i = 0; i < n; i++)
    {
        if (map[arr[i]] > value)
        {
            key = arr[i];
            value = map[arr[i]];
        }
    }
    return key;
}
