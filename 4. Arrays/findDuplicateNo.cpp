// find the duplicate no in the given array also

// Method-1
// Complexities : TC - O(n^2) , SC - O(1)

// #include <iostream>
// using namespace std;
// int duplicateNumber(int *arr, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (i != j && arr[i] == arr[j])
//                 return arr[i];
//         }
//     }
// }
// int main()
// {
//     int n;
//     cin >> n;
//     int *arr = new int[n];
//     for (int i = 0; i < n; i++)
//         cin >> arr[i];
//     cout << duplicateNumber(arr, n);
//     return 0;
// }

// Method-2 - using sliding window technique
// Complexities : TC - O(n) , SC - O(1)

// #include<bits/stdc++.h>
// using namespace std;
// int duplicateNumber(int *arr, int n)
// {
//     int freq[256] = {0};
//     for (int i = 0; i < n; i++)
//         freq[arr[i]]++;
//     for (int i = 0; i < n; i++)
//     {
//         if (freq[arr[i]] >= 2)
//             return arr[i];
//     }
// }
// int main()
// {
//     int n;
//     cin >> n;
//     int *arr = new int[n];
//     for (int i = 0; i < n; i++)
//         cin >> arr[i];
//     cout << duplicateNumber(arr, n);
//     return 0;
//     return 0;
// }

// Method-3
// Complexities : TC - O(n) , SC - O(1)

// #include <bits/stdc++.h>
// using namespace std;
// int duplicateNumber(int *arr, int n)
// {
//     int sum1 = 0;
//     for (int i = 0; i < n; i++)
//         sum1 += arr[i];
//     int sum2 = 0;
//     for (int i = 0; i <= n - 2; i++)
//         sum2 += i;
//     return sum1 - sum2;
// }
// int main()
// {
//     int n;
//     cin >> n;
//     int *arr = new int[n];
//     for (int i = 0; i < n; i++)
//         cin >> arr[i];
//     cout << duplicateNumber(arr, n) << endl;
//     return 0;
// }

// Method-4 - using xor
// Complexities : TC - O(n) , SC - O(1)

#include <bits/stdc++.h>
using namespace std;
int duplicateNumber(int *arr, int n)
{
    int c = 0;
    for (int i = 0; i < n; i++)
        c ^= arr[i];
    for (int i = 0; i <= n - 2; i++)
        c ^= i;
    return c;
}
int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << duplicateNumber(arr, n) << endl;
    return 0;
}