#include <bits/stdc++.h>
using namespace std;
// Iterative
double myPow(double x, int n)
{
    double ans = 1.0;
    long long nn = n;
    if (n < 0)
        nn = -1 * nn;
    while (nn)
    {
        if (nn % 2)
        {
            // odd
            ans = ans * x;
            nn = nn - 1;
        }
        else
        {
            // even
            x = x * x;
            nn = nn / 2;
        }
    }
    if (n < 0)
        ans = (double)(1.0) / (double)(ans);
    return ans;
}

// Recursive
double myPow(double x, int n)
{
    if (n == 0)
        return 1;
    if (n < 0)
    {
        if (n == INT_MIN)
            return 1.0 / (myPow(x, INT_MAX) * x);
        return 1.0 / myPow(x, -n);
    }
    if (n % 2)
        return x * myPow(x, n - 1);
    return myPow(x * x, n / 2);     //even->square the base and half the power
}