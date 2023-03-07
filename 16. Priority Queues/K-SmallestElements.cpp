#include <bits/stdc++.h>
using namespace std;
vector<int> kSmallest(int input[], int n, int k)
{
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
        pq.push(input[i]);
    for (int i = k; i < n; i++)
    {
        int maxElement = pq.top();
        if (input[i] < maxElement)
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
    vector<int> v = kSmallest(input, 5, k);
    for (int i : v)
        cout << i << " ";
    return 0;
}