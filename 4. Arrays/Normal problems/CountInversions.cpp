#include <bits/stdc++.h>
using namespace std;
int merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;    // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1; // starting index of right half of arr

    // storing elements in the temporary array in a sorted manner//
    int count = 0;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            count += (mid - left + 1);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
    return count;
}

int mergeSort(vector<int> &arr, int low, int high)
{
    int count = 0;
    if (low >= high)
        return count;
    int mid = (low + high) / 2;
    count += mergeSort(arr, low, mid);      // left half
    count += mergeSort(arr, mid + 1, high); // right half
    count += merge(arr, low, mid, high);    // merging sorted halves
    return count;
}
int numberOfInversions(vector<int> &a, int n)
{
    return mergeSort(a, 0, n - 1);
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout << numberOfInversions(a, n);
}