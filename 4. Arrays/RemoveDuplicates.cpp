#include <bits/stdc++.h>
using namespace std;
int removeDuplicates(int arr[], int n)
{
    if (n == 0 || n == 1)
        return n;
    sort(arr, arr + n);
    int *temp = new int[n];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != arr[i + 1])
            temp[j++] = arr[i];
    }
    for (int i = 0; i < j; i++)
        arr[i] = temp[i];
    return j;
}
// using set
int removeDuplicates1(vector<int> &nums)
{
    set<int> s;
    for (int i = 0; i < nums.size(); i++)
        s.insert(nums[i]);

    nums.clear();
    for (auto i : s)
        nums.push_back(i);
        
    return s.size();
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    n = removeDuplicates(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}