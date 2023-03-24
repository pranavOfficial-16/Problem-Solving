#include <iostream>
using namespace std;

// bruteforce
int pairSum(int *a, int n, int x)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] + a[j] == x)
                count++;
        }
    }
    return count;
}

// optimal - the array should be sorted for this to work
int pairSum1(int *a, int n, int x)
{
    int low = 0;
    int high = n - 1;
    int count = 0;
    while (low < high)
    {
        if (a[low] + a[high] == x)
        {
            count++;
            low++;
            high--;
        }
        else if (a[low] + a[high] < x)
            low++;
        else
            high--;
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
    int x;
    cin >> x;
    cout << pairSum1(a, n, x);
    return 0;
}