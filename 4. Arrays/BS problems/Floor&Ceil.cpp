#include <bits/stdc++.h>
using namespace std;
int findFloor(vector<int> &v, int n, int x)
{
    int low = 0;
    int high = n - 1;
    int mid, result = -1;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (v[mid] > x)
            high = mid - 1;
        else if (v[mid] < x)
        {
            result = v[mid];
            low = mid + 1;
        }
        else
            return v[mid];
    }
    return result;
}
int findCeil(vector<int> &v, int n, int x)
{
    int low = 0;
    int high = n - 1;
    int mid, result = -1;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (v[mid] > x)
        {
            result = v[mid];
            high = mid - 1;
        }
        else if (v[mid] < x)
        {
            low = mid + 1;
        }
        else
            return v[mid];
    }
    return result;
}
vector<int> getFloorAndCeil(int x, vector<int> &arr)
{
    sort(arr.begin(), arr.end());
    int floor = findFloor(arr, arr.size(), x);
    int ceil = findCeil(arr, arr.size(), x);
    return {floor, ceil};
}