#include <bits/stdc++.h>
using namespace std;
bool checkStrong(int n)
{
    int temp = n;
    int rem, sum = 0;
    int i, fact;
    while (n)
    {
        rem = n % 10;
        i = fact = 1;
        while (i <= rem)
        {
            fact *= i;
            i++;
        }
        sum += fact;
        n /= 10;
    }
    if (sum == temp)
        return true;
    return false;
}
int main()
{
    int n;
    cin >> n;
    if (checkStrong(n))
        cout << "true";
    else
        cout << "false";
    return 0;
}