// For binary search to work the array should be sorted

// binary search using recusion
// Time Complexity: O(log n)
// Space Complexity: O(1)
// #include <iostream>
// using namespace std;
// int binarySearch(int *a, int s, int e, int k)
// {
//     // base case 1
//     // element not found
//     if (s > e)
//         return -1;
//     int mid = s + (e - s) / 2;
//     // base case 2
//     // element found
//     if (a[mid] == k)
//         return mid;
//     if (a[mid] < k)
//         return binarySearch(a, mid + 1, e, k);
//     else
//         return binarySearch(a, s, mid - 1, k);
// }
// int main()
// {
//     int n;
//     cin >> n;
//     int *a = new int[n];
//     for (int i = 0; i < n; i++)
//         cin >> a[i];
//     int key;
//     cin >> key;
//     cout<< binarySearch(a,0,n-1,key);
//     return 0;
// }

// binary search using iterative approach
// Time Complexity: O(log n)
// Space Complexity: O(1)
#include <iostream>
using namespace std;
int binarySearch(int *a, int n, int key)
{
    int s = 0, e = n - 1, mid;
    while (s <= e)
    {
        mid = s + (e - s) / 2;
        if (a[mid] == key)
            return mid;
        else if (key < a[mid])
            e = mid - 1;
        else
            s = mid + 1;
    }
    return -1;
}
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int key;
    cin >> key;
    cout << binarySearch(a, n, key);
    return 0;
}