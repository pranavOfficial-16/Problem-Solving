// find the unique no in the given array also

// Method-1
// Complexities : TC - O(n^2) , SC - O(1)

// #include <iostream>
// using namespace std;
// int findUnique(int *arr, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         int j = 0;
//         for (; j < n; j++)
//         {
//             if (i != j && arr[i] == arr[j])
//                 break;
//         }
//         if (j == n)
//             return arr[i];
//     }
// }
// int main()
// {
//     int n;
//     cin >> n;
//     int arr[n];
//     for (int i = 0; i < n; i++)
//         cin >> arr[i];
//     cout << findUnique(arr, n);
//     return 0;
// }

// Method-2 --> using sliding window technique
// Complexities : TC - O(n) , SC - O(1)

// #include<bits/stdc++.h>
// using namespace std;
// int findUnique(int *arr, int n)
// {
//     int freq[256] = {0};
//     for (int i = 0; i < n; i++)
//     {
//         freq[arr[i]]++;
//     }
//     for (int i = 0; i < n; i++)
//     {
//         if (freq[arr[i]] == 1)
//             return arr[i];
//     }
// }
// int main()
// {
//     int n;
//     cin >> n;
//     int a[n];
//     for (int i = 0; i < n; i++)
//         cin >> a[i];
//     cout<<findUnique(a, n);
//     return 0;
// }

// Method-3 --> using xor property i.e.. Bitmasking
// Complexities : TC - O(n) , SC - O(1)
#include <bits/stdc++.h>
using namespace std;
int findUnique(int *arr, int n)
{
    int c = arr[0];
    for (int i = 1; i < n; i++)
        c = c ^ arr[i];
    return c;
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << findUnique(arr, n) << endl;
    return 0;
}