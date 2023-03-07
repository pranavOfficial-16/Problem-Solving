// To find the second largest element
// method-1
// #include <bits/stdc++.h>
// using namespace std;
// int main()
// {
//     long n;
//     cin >> n;
//     long a[n];
//     if (n <= 2)
//     {
//         cout << INT_MIN;
//         return 0;
//     }
//     for (int i = 0; i < n; i++)
//         cin >> a[i];
//     sort(a, a + n);
//     for (int i = n - 2; i >= 0; i--)
//     {
//         if (a[i] != a[n - 1])
//         {
//             cout << a[i];
//             return 0;
//         }
//     }
// }

// method-2
#include <bits/stdc++.h>
using namespace std;
int findSecondLargest(int *a, int n)
{
    int max = -1, secondMax = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            secondMax = max;
            max = a[i];
        }
        else if (a[i] > secondMax && a[i] != max)
            secondMax = a[i];
    }
    return secondMax;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout <<findSecondLargest(a,n);
}
