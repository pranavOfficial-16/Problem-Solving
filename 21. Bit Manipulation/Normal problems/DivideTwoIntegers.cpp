#include <bits/stdc++.h>
using namespace std;
int divide(int dividend, int divisor)
{
    if (dividend == divisor)
        return 1;
    bool sign = true;
    if (dividend >= 0 && divisor < 0)
        sign = false;
    else if (dividend <= 0 && divisor > 0)
        sign = false;
    long n = abs(dividend), d = abs(divisor);
    long ans = 0, count;
    while (n >= d)
    {
        count = 0;
        while (n >= (d << (count + 1)))
            count++;
        ans += (1 << count);
        n -= (d << count);
    }
    if (ans == (1 << 31) && sign)
        return INT_MAX;
    if (ans == (1 << 31) && !sign)
        return INT_MIN;
    return sign ? ans : -ans;
}