#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n];
    int t1 = 1, t2 = 1;
    a[0] = t1;
    a[1] = t2;
    for (int i = 0; i < n; i++)
    {
        int nextterm = t1 + t2;
        a[i + 2] = nextterm;
        t1 = t2;
        t2 = nextterm;
    }
    cout << a[n - 1];
    return 0;
}