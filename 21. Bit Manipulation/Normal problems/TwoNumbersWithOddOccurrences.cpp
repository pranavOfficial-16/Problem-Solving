#include <bits/stdc++.h>
using namespace std;
vector<long long int> twoOddNum(long long int arr[], long long int n)
{
    //  XOR all elements
    long long int Xor = 0;
    for (int i = 0; i < n; i++)
        Xor ^= arr[i];

    // Find the rightmost set bit
    long long int setbit = Xor & ~(Xor - 1);

    // Find the two unique elements
    long long int first = 0, second = 0;
    for (int i = 0; i < n; i++)
    {
        if ((arr[i] & setbit) != 0)
            first ^= arr[i];
        else
            second ^= arr[i];
    }

    if (first > second)
        return {first, second};

    return {second, first};
}