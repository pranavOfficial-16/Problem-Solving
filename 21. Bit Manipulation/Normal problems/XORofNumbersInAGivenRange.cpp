#include <bits/stdc++.h>
using namespace std;
int findTheXOR(int n)
{
    if (n % 4 == 1)
        return 1;
    if (n % 4 == 2)
        return n + 1;
    if (n % 4 == 3)
        return 0;
    if (n % 4 == 0)
        return n;
}
int findXOR(int l, int r)
{
    return findTheXOR(l - 1) ^ findTheXOR(r);
}