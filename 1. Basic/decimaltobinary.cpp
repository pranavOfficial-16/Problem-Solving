#include <iostream>
using namespace std;
int main()
{
    long n, digit, i = 0;
    cin >> n;
    long a[50];
    while (n != 0)
    {
        digit = n % 2;
        a[i] = digit;
        n = n / 2;
        i++;
    }
    for (long j = i - 1; j >= 0; j--)
    {
        cout << a[j];
    }
    return 0;
}