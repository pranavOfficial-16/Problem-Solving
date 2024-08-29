// To find the second largest element
#include <bits/stdc++.h>
using namespace std;
int findSecondLargest(int *a, int n)
{
    int max = -1, secondMax = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            secondMax = max;
            max = a[i];
        }
        else if (a[i] > secondMax && a[i] != max)
            secondMax = a[i];
    }
    return secondMax;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout <<findSecondLargest(a,n);
}
