#include <bits/stdc++.h>
using namespace std;
int buyTicket(int *input, int n, int k)
{
    queue<int> q;
    for (int i = 0; i < n; i++)
        q.push(i);
    priority_queue<int> pq;
    for (int i = 0; i < n; i++)
        pq.push(input[i]);

    int time = 0;
    while (q.front() != k || pq.top() != input[q.front()])
    {
        if (input[q.front()] == pq.top())
        {
            q.pop();
            pq.pop();
            time++;
        }
        else
        {
            int temp = q.front();
            q.pop();
            q.push(temp);
        }
    }
    return time + 1;
}
int main()
{
    int input[] = {2, 3, 2, 2, 4};
    int n = 5;
    int k = 3;
    cout << buyTicket(input, n, k) << endl;
    return 0;
}