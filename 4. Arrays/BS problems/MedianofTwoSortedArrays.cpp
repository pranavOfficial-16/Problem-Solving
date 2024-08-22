#include <bits/stdc++.h>
using namespace std;
double findMedianSortedArrays(vector<int> &a1, vector<int> &a2)
{
    int n1 = a1.size();
    int n2 = a2.size();
    vector<int> a3(n1 + n2);
    int i = 0, j = 0, next = 0;
    while (i < n1 && j < n2)
    {
        if (a1[i] < a2[j])
            a3[next++] = a1[i++];
        else
            a3[next++] = a2[j++];
    }
    while (i < n1)
        a3[next++] = a1[i++];
    while (j < n2)
        a3[next++] = a2[j++];

    int n3 = a3.size();
    int low = 0, high = n3 - 1;
    int mid = low + (high - low) / 2;
    if (n3 % 2 == 0)
    {
        // even
        double secondmid = (a3[mid] + a3[mid + 1]) / 2.0;
        return secondmid;
    }
    else
    {
        // odd
        return (double)a3[mid];
    }
}