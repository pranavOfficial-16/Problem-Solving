#include <iostream>
using namespace std;
int main()
{
    int n, c;
    cin >> n >> c;
    int sum, prod;
    switch (c)
    {
    case 1:
        sum = 0;
        for (int i = 1; i <= n; i++)
        {
            sum += i;
        }
        cout << sum;
        break;
    case 2:
        prod = 1;
        for (int i = 1; i <= n; i++)
        {
            prod *= i;
        }
        cout << prod;
        break;
    default:
        cout << "-1";
    }
    return 0;
}
