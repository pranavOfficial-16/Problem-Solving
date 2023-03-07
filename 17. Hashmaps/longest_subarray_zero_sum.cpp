#include <bits/stdc++.h>
using namespace std;
int lengthOfLongestSubsetWithZeroSum(int *arr, int n)
{
    unordered_map<int, int> map;
    int length = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (arr[i] == 0 && length == 0)
            length = 1;
        if (sum == 0)
            length = i + 1;
        if (map.count(sum) > 0)
            length = max(length, i - map[sum]);
        else
            map[sum] = i;
    }
    return length;
}
