// sort an array containing zeros and ones
#include <iostream>
using namespace std;
void sortZeroesAndOne(int *a, int n)
{
    int temp[n];
    for (int i = 0; i < n; i++)
        temp[i] = a[i];
    int j = 0, k = n - 1;
    for (int i = 0; i < n; i++)
    {
        if (temp[i] == 0)
            a[j++] = 0;
        else
            a[k--] = 1;
    }
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sortZeroesAndOne(a,n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}