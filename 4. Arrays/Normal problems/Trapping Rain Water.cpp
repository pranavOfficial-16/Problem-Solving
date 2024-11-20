#include <bits/stdc++.h>
using namespace std;

/*
    Optimal
        TC -> O(n)
        SC -> O(1)
*/

// 2 pointer approach
int trap(vector<int> &height)
{
    int n = height.size();
    int lmax = 0, rmax = 0, l = 0, r = n - 1, total = 0;
    while (l < r)
    {
        if (height[l] <= height[r])
        {
            if (lmax > height[l])
                total += (lmax - height[l]);
            else
                lmax = height[l];
            l++;
        }
        else
        {
            if (rmax > height[r])
                total += (rmax - height[r]);
            else
                rmax = height[r];
            r--;
        }
    }
    return total;
}