#include <bits/stdc++.h>
using namespace std;
vector<int> replaceWithRank(vector<int> &arr, int N)
{
    priority_queue<int, vector<int>, greater<int>> minHeap;

    for (int num : arr)
    {
        minHeap.push(num);
    }

    unordered_map<int, int> rankMap;
    int rank = 1;

    while (!minHeap.empty())
    {
        int num = minHeap.top();
        minHeap.pop();

        if (rankMap.find(num) == rankMap.end())
        {
            rankMap[num] = rank++;
        }
    }

    for (int i = 0; i < N; i++)
    {
        arr[i] = rankMap[arr[i]];
    }

    return arr;
}