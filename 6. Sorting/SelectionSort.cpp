/*
    Selection sort
    (asc) -> find the min element and swap it in begining and so on
    (dec) -> find the max element and swap it in begining and so on
*/
#include <bits/stdc++.h>
using namespace std;
void selectionsort(int *a, int n)
{
    int temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[i])
            {
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }
}
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    selectionsort(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}