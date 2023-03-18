#include <bits/stdc++.h>
using namespace std;
int pairSum(int *arr, int n)
{
    int sum = 0;
    unordered_map<int, int> map;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int value = sum - arr[i];
        if (map[value])
            count += map[value];
        map[arr[i]]++;
    }
    return count;
}
int main()
{
    int arr[] = {2, 1, -2, 2, 3};
    cout << pairSum(arr, 5);
}
