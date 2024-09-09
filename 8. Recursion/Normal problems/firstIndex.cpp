#include <iostream>
using namespace std;
int firstindex(int *a, int n, int x)
{
    if (n == 0)
        return -1;
    else if (a[0] == x)
        return 0;
    else
    {
        int ans = firstindex(a + 1, n - 1, x);
        if (ans == -1)
            return -1;
        else
            return ans + 1;
    }
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
    cout << firstindex(a, n, x);
    return 0;
}