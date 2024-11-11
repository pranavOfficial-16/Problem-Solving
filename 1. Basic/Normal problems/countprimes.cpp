#include <bits/stdc++.h>
using namespace std;
int countPrimes(int n)
{
    if (n <= 2)
        return 0;

    int count = 0;
    vector<bool> check(n, false);

    for (int i = 2; i * i < n; i++)
    {
        if (!check[i])
        {
            for (int j = i * i; j < n; j += i)
            {
                check[j] = true;
            }
        }
    }

    for (int i = 2; i < n; i++)
    {
        if (!check[i])
            count++;
    }

    return count;
}