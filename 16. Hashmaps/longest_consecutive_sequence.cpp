#include <bits/stdc++.h>
using namespace std;
vector<int> longestConsecutiveIncreasingSequence(int *arr, int n)
{
    unordered_map<int, bool> map;
    vector<int> v;
    for (int i = 0; i < n; i++)
        map[arr[i]] = true;
    int maxLength = 0;
    int startElement = 0;
    for (int i = 0; i < n; i++)
    {
        int currElement = arr[i];
        int currLength = 0;
        if (map[currElement - 1])
            continue;
        while (map[currElement])
        {
            currElement++;
            currLength++;
        }
        if (currLength > maxLength)
        {
            maxLength = currLength;
            startElement = arr[i];
        }
    }
    v.push_back(startElement);
    if (maxLength > 1)
        v.push_back(startElement + maxLength - 1);
    return v;
}
