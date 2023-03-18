#include <bits/stdc++.h>
using namespace std;
bool isMaxHeap(int input[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int parentIndex = i;
        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 1;
        if (leftChildIndex < n && input[parentIndex] < input[leftChildIndex])
            return false;
        if (rightChildIndex < n && input[parentIndex] < input[rightChildIndex])
            return false;
    }
    return true;
}