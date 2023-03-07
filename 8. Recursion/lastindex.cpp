#include <iostream>
using namespace std;
int lastindex(int *a, int n, int x)
{
    n--;
    if (n < 0)
        return -1;
    if (a[n] == x)
        return n;
    return lastindex(a,n,x);
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int x;
    cin >> x;
    cout << lastindex(a, n, x);
    return 0;
}