#include <bits/stdc++.h>
#include "MinPriorityQueue.h"
using namespace std;
// inplace means using the same array instead of using extra space
void inplaceHeapSort(int pq[], int n)
{
    // build the heap in input array

    for (int i = 1; i < n; i++)
    {
        int childIndex = i;
        while (childIndex > 0)
        {
            int parentIndex = (childIndex - 1) / 2;
            if (pq[childIndex] < pq[parentIndex])
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
    // build elements

    int size = n;
    while (size > 1)
    {
        int temp = pq[0];
        pq[0] = pq[size - 1];
        pq[size - 1] = temp;

        size--;

        int parentIndex = 0;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;
        while (leftChildIndex < size)
        {
            int minIndex = parentIndex;
            if (pq[minIndex] > pq[leftChildIndex])
            {
                minIndex = leftChildIndex;
            }
            if (rightChildIndex < size && pq[minIndex] > pq[rightChildIndex])
            {
                minIndex = rightChildIndex;
            }
            if (minIndex == parentIndex)
                break;
            int temp = pq[minIndex];
            pq[minIndex] = pq[parentIndex];
            pq[parentIndex] = temp;

            parentIndex = minIndex;
            leftChildIndex = 2 * parentIndex + 1;
            rightChildIndex = 2 * parentIndex + 2;
        }
    }
}
int main()
{
    int input[] = {10, 12, 6, 7, 9};
    inplaceHeapSort(input, 5);
    for (int i = 0; i < 5; i++)
        cout << input[i] << " ";
    return 0;
}