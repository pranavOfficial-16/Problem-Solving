#include <bits/stdc++.h>
using namespace std;
void printalldivisors(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            cout << i << " ";
    }
}
int main()
{
    int n;
    cin >> n;
    printalldivisors(n);
    return 0;
}