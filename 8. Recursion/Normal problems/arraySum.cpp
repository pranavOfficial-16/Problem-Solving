#include <iostream>
using namespace std;
int arraysum(int *a, int n)
{
    if (n <= 0)
        return 0;
    return arraysum(a,n-1)+a[n-1];
}
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cout<<arraysum(a,n);
    return 0;
}