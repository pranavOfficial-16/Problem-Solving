#include <bits/stdc++.h>
using namespace std;
// find whether the array with specific start and end index is distinct or not
bool distinct(int *arr, int start, int end)
{
    unordered_map<int, int> mpp;
    for (int i = start; i <= end; i++)
        mpp[arr[i]]++;
    for (int i = start; i <= end; i++)
    {
        if (mpp[arr[i]] > 1)
            return false;
    }
    return true;
}
int main()
{
    int n, start, end;
    cin >> n >> start >> end;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    (distinct(arr, start, end))
        ? cout << "distinct"
        : cout << "Not distinct";
    return 0;
}