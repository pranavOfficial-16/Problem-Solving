// sort an array containing twos and zeros and ones
#include <iostream>
using namespace std;
void sort012(int *a, int n)
{
    int temp[n];
    for (int i = 0; i < n; i++)
        temp[i] = a[i];
    int j = 0, k = n - 1, twos = 0;
    for (int i = 0; i < n; i++)
    {
        if (temp[i] == 0)
            a[j++] = 0;
        else if (temp[i] == 1)
            a[k--] = 1;
        else
        {
            a[k--] = 1;
            twos++;
        }
    }
    for (int i = n - 1; i >= n - twos; i--)
        a[i] = 2;
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort012(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}