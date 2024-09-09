#include <iostream>
using namespace std;
bool sorted(int *a, int n)
{
    if (n == 0)
        return true;
    if (a[0] > a[1])
        return false;
    bool check = sorted(a + 1, n - 1);
    return check;
}
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sorted(a, n) ? cout << "sorted" : cout << "not sorted";
    return 0;
}