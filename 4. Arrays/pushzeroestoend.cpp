#include <iostream>
using namespace std;
void zeroestoend(int *a, int n)
{
    int next = 0, temp[n];
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 0)
            temp[next++] = a[i];
    }
    for (int i = next; i < n; i++)
        temp[i] = 0;
    for (int i = 0; i < n; i++)
        a[i] = temp[i];
}
int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    zeroestoend(a, n);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    return 0;
}