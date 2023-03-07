// rotate the array towards the left by d elements
#include <bits/stdc++.h>
using namespace std;
void rotate(int *a, int d, int n)
{
    int *temp = new int[n];
    int next = 0;
    for (int i = d; i < n; i++)
        temp[next++] = a[i];
    for (int i = 0; i < d; i++)
        temp[next++] = a[i];
    for (int i = 0; i < n; i++)
        a[i] = temp[i];
}
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int d;
    cin >> d;
    rotate(a, d, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}