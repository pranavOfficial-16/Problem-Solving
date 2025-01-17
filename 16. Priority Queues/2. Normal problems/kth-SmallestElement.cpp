#include <bits/stdc++.h>
using namespace std;
int findKthSmallest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < nums.size(); i++)
        pq.push(nums[i]);
    while (k - 1 > 0)
    {
        pq.pop();
        k--;
    }
    return pq.top();
}