#include <iostream>
using namespace std;
bool checkNumber(int *a, int n, int x)
{
    n--;
    if (n < 0)
        return false;
    if (a[n] == x)
        return true;
    return checkNumber(a,n, x);
}

int main()
{
    int n;
    cin >> n;
    int x;
    cin >> x;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << checkNumber(a, n, x);
    return 0;
}