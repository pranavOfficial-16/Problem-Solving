#include <bits/stdc++.h>
using namespace std;
vector<int> mergeKArrays(vector<vector<int>> input, int K)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < input.size(); i++)
        for (int j = 0; j < input[0].size(); j++)
            pq.push(input[i][j]);
    vector<int> v;
    while (!pq.empty())
    {
        v.push_back(pq.top());
        pq.pop();
    }
    return v;
}