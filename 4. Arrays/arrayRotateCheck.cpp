#include<bits/stdc++.h>
using namespace std;
int arrayRotateCheck(int *a,int n)
{
    int mi = INT_MAX;
    for (int i = 0; i < n; i++)
        mi = min(mi, a[i]);
    for (int i = 0; i < n; i++)
    {
        if (a[i] == mi)
            return i;
    }
}
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << arrayRotateCheck(a,n);
    return 0;
}