#include <bits/stdc++.h>
using namespace std;
int findPlatform(vector<int> &arr, vector<int> &dep)
{
    sort(arr.begin(), arr.end());
    sort(dep.begin(), dep.end());

    int n = arr.size();
    int count = 0, i = 0, j = 0, maxcount = 0;
    while (i < n)
    {
        if (arr[i] <= dep[j]) 
        {
            count++;
            i++;
        }
        else 
        {
            count--;
            j++;
        }
        maxcount = max(maxcount, count);
    }
    return maxcount;
}