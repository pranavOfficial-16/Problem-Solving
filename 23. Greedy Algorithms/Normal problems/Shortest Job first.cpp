#include <bits/stdc++.h>
using namespace std;
long long solve(vector<int> &bt)
{
    sort(bt.begin(), bt.end());
    long long wt = 0, t = 0;
    for (int i = 0; i < bt.size(); i++)
    {
        wt += t;
        t += bt[i];
    }
    return wt / bt.size();
}