#include <bits/stdc++.h>
using namespace std;
vector<int> topKFrequent(vector<int> &nums, int k)
{
    unordered_map<int, int> freq;

    for (int num : nums)
    {
        freq[num]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>
        minHeap;

    for (auto &it : freq)
    {
        minHeap.push({it.second, it.first});
        if (minHeap.size() > k)
        {
            minHeap.pop();
        }
    }

    vector<int> result;
    while (!minHeap.empty())
    {
        result.push_back(
            minHeap.top().second);
        minHeap.pop();
    }

    return result;
}