#include <bits/stdc++.h>
using namespace std;
int pairSum(int *arr, int n)
{
    int sum = 6;
    unordered_map<int, int> map;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (map.find(sum - arr[i]) != map.end())
            count += map[sum - arr[i]];
        map[arr[i]]++;
    }
    return count;
}
int main()
{
    int arr[] = {1, 5, 7, -1, 5};
    cout << pairSum(arr, 5);
}
