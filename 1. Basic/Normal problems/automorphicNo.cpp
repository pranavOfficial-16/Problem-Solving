#include <bits/stdc++.h>
using namespace std;
bool check(int n)
{
    int sq = n * n;
    int i = 1;
    while (n)
    {
        int rem1 = sq % 10;
        int rem2 = n % 10;

        if (rem1 != rem2)
            return false;

        sq /= 10;
        n /= 10;
    }
    return true;
}
int main()
{
    int n;
    cin >> n;
    if (check(n))
        cout << "true";
    else
        cout << "false";
    return 0;
}