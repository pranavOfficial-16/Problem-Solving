#include <bits/stdc++.h>
using namespace std;
int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < nums.size(); i++)
        pq.push(nums[i]);
    while (k - 1 > 0)
    {
        pq.pop();
        k--;
    }
    return pq.top();
}