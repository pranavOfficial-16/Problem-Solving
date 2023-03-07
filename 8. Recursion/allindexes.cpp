#include <iostream>
using namespace std;
int allindexes(int *a, int n, int x, int *b)
{
    if (n == 0)
        return 0;
    int smallAns = allindexes(a, n - 1, x, b);
    if (a[n - 1] == x)
        b[smallAns++] = n - 1;
    return smallAns;
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
    int *b = new int[n];
    int size = allindexes(a, n, x, b);
    for (int i = 0; i < size; i++)
        cout << b[i] << " ";
    return 0;
}