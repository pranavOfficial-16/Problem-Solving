#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int digit, rev=0;
    while (n != 0)
    {
        digit = n % 10;
        rev = (rev * 10) + digit;
        n = n / 10;
    }
    cout << rev;
    return 0;
}
