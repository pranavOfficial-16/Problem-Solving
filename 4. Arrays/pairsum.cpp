// Find and return the total number of pairs in the array which sum to x.
#include <iostream>
using namespace std;
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
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int x;
    cin >> x;
    cout << pairSum(a, n, x);
    return 0;
}