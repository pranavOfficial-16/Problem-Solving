// Max priority queue i.e.. Max Heap
#include <bits/stdc++.h>
using namespace std;
class PriorityQueue
{
    vector<int> pq;

public:
    bool isEmpty()
    {
        return pq.size() == 0;
    }
    int getSize()
    {
        return pq.size();
    }
    int getMax()
    {
        if (isEmpty())
            return INT_MAX;
        return pq[0];
    }
    void insert(int element)
    {
        pq.push_back(element);
        int childIndex = getSize() - 1;
        // up-heapify
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[childIndex] > pq[parentIndex])
            {
                int temp = pq[childIndex];
                pq[childIndex] = pq[parentIndex];
                pq[parentIndex] = temp;
            }
            else
                break;
            childIndex = parentIndex;
        }
    }
    int removeMax()
    {
        if (isEmpty())
            return 0;
        int ans = pq[0];
        pq[0] = pq[getSize() - 1];
        pq.pop_back();
        // down-heapify
        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;
        while (leftChildIndex < getSize())
        {
            int maxIndex = parentIndex;
            if (pq[maxIndex] < pq[leftChildIndex])
                maxIndex = leftChildIndex;
            if (rightChildIndex < getSize() && pq[maxIndex] < pq[rightChildIndex])
                maxIndex = rightChildIndex;
            if (maxIndex == parentIndex)
                break;
            int temp = pq[maxIndex];
            pq[maxIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = maxIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }
        return ans;
    }
};