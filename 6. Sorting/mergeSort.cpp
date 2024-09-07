// Time complexity : O(nlogn)
// Space Complexity : O(n)
#include <bits/stdc++.h>
using namespace std;
/*
    void merge(int *arr, int s, int e)
    {
        int mid = s + (e - s) / 2;

        int len1 = mid - s + 1;
        int len2 = e - mid;

        int *first = new int[len1];
        int *second = new int[len2];

        // copy values
        int k = s;
        for (int i = 0; i < len1; i++)
            first[i] = arr[k++];
        k = mid + 1;
        for (int i = 0; i < len2; i++)
            second[i] = arr[k++];

        // merge the sorted arrays
        int i = 0, j = 0, next = s;
        while (i < len1 && j < len2)
        {
            if (first[i] < second[j])
                arr[next++] = first[i++];
            else
                arr[next++] = second[j++];
        }
        while (i < len1)
            arr[next++] = first[i++];
        while (j < len2)
            arr[next++] = second[j++];
    }
*/
void merge(int *arr, int s, int mid, int e)
{

    int left = s;
    int right = mid + 1;
    vector<int> sortedarr;
    while (left <= mid && right <= e)
    {
        if (arr[left] <= arr[right])
        {
            sortedarr.push_back(arr[left]);
            left++;
        }
        else
        {
            sortedarr.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        sortedarr.push_back(arr[left]);
        left++;
    }
    while (right <= e)
    {
        sortedarr.push_back(arr[right]);
        right++;
    }
    // transfering all elements from temporary to arr //
    for (int i = s; i <= e; i++)
        arr[i] = sortedarr[i - s];
}
void mergeSort(int *arr, int s, int e)
{
    // base case
    if (s >= e)
        return;
    int mid = s + (e - s) / 2;

    // left array sort
    mergeSort(arr, s, mid);

    // right array sort
    mergeSort(arr, mid + 1, e);

    // merge
    // merge(arr, s, e); or
    merge(arr, s, mid, e);
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}