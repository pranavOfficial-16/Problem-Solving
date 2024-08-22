#include <bits/stdc++.h>
using namespace std;
int solve(vector<int> &arr, int pages)
{
    int noOfStudents = 1, pagesStudent = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (pagesStudent + arr[i] <= pages)
            pagesStudent += arr[i];
        else
        {
            noOfStudents++;
            pagesStudent = arr[i];
        }
    }
    return noOfStudents;
}
int findPages(vector<int> &arr, int n, int m)
{
    // edge case
    if (m > n)
        return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while (low <= high)
    {
        int mid = (low + high) / 2;
        int noOfStudents = solve(arr, mid);
        if (noOfStudents > m)
            low = mid + 1;
        else
            high = mid - 1;
    }
}
