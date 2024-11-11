#include <bits/stdc++.h>
using namespace std;
void rev(int i, int j, string s)
{
    if (i > j)
        return;
    swap(s[i], s[j]);
    i++;
    j--;
    rev(i, j, s);
}