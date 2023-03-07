#include <bits/stdc++.h>
using namespace std;
vector<int> kLargest(int input[], int n, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k; i++)
        pq.push(input[i]);
    for (int i = k; i < n; i++)
    {
        int minElement = pq.top();
        if (input[i] > minElement)
        {
            pq.pop();
            pq.push(input[i]);
        }
    }
    vector<int> v;
    while (!pq.empty())
    {
        int element = pq.top();
        v.push_back(element);
        pq.pop();
    }
    return v;
}
int main()
{
    int input[] = {10, 12, 6, 7, 9};
    int k = 3;
    vector<int> v = kLargest(input, 5, k);
    for (int i : v)
        cout << i << " ";
    return 0;
}