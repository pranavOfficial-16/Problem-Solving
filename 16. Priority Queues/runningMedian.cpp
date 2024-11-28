#include <bits/stdc++.h>
using namespace std;
void findMedian(int *input, int n)
{
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < n; i++)
    {
        if (maxHeap.size() == 0 || input[i] < maxHeap.top())
            maxHeap.push(input[i]);
        else
            minHeap.push(input[i]);

        if (abs(maxHeap.size() - minHeap.size()) > 1)
        {
            if (maxHeap.size() > minHeap.size())
            {
                int temp = maxHeap.top();
                maxHeap.pop();
                minHeap.push(temp);
            }
            else
            {
                int temp = minHeap.top();
                minHeap.pop();
                maxHeap.push(temp);
            }
        }

        if (maxHeap.size() == minHeap.size())
        {
            int median = (maxHeap.top() + minHeap.top()) / 2;
            cout << median << " ";
        }
        else
        {
            if (maxHeap.size() > minHeap.size())
                cout << maxHeap.top() << " ";
            else
                cout << minHeap.top() << " ";
        }
    }
}
int main()
{
    int input[] = {6, 2, 1, 3, 7, 5};
    findMedian(input, 6);
    return 0;
}