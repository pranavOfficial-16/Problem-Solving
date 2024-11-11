#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long myPow(long long x, long long n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return myPow((x * x) % mod, n / 2);
    else
        return (x * myPow(x, n - 1)) % mod;
}
int countGoodNumbers(long long n)
{
    long long even = (n + 1) / 2;
    long long odd = n / 2;
    return (myPow(5, even) * myPow(4, odd)) % mod;
}
int main()
{
    int n;
    cin >> n;
    cout << countGoodNumbers(n);
    return 0;
}