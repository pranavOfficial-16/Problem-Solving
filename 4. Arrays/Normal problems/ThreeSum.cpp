//  Find and return the total number of triplet pairs in the array which sum to x.

//  Method-1 - using 3 loops
//  SC - O(1) , TC - o(n^3)
// #include <iostream>
// using namespace std;
// int tripletSum(int *a, int n, int x)
// {
//     int count = 0;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             for (int k = j + 1; k < n; k++)
//                 if (a[i] + a[j] + a[k] == x)
//                     count++;
//         }
//     }
//     return count;
// }
// int main()
// {
//     int n;
//     cin >> n;
//     int a[n];
//     for (int i = 0; i < n; i++)
//         cin >> a[i];
//     int x;
//     cin >> x;
//     cout << tripletSum(a, n, x);
//     return 0;
// }

//  Method-2 - using 2 loops ( optimized )
//  SC - O(1) , TC - o(n^2)
#include <bits/stdc++.h>
using namespace std;
int tripletSum(int *a, int n, int k)
{
    int count = 0, s, e, sum;
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && a[i] == a[i - 1])
            continue;
        s = i + 1;
        e = n - 1;
        while (s < e)
        {
            sum = a[i] + a[s] + a[e];
            if (sum < 0)
                s++;
            else if (sum > 0)
                e--;
            else
            {
                count++;
                s++;
                e--;
                while (s < e && a[s] == a[s - 1])
                    s++;
                while (s < e && a[e] == a[e + 1])
                    e--;
            }
        }
    }
    return count;
}
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int k;
    cin >> k;
    cout << tripletSum(a, n, k);
    return 0;
}
