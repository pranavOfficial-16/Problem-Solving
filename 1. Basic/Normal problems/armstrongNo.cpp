#include <bits/stdc++.h>
using namespace std;
string armstrongNumber(int n)
{
    int rem, temp, sum = 0;
    temp = n;
    while (n)
    {
        rem = n % 10;
        sum += pow(rem, 3);
        n /= 10;
    }
    if (sum == temp)
        return "Yes";
    else
        return "No";
}
int main()
{
    int n;
    cin>>n;
    cout<<armstrongNumber(n);
    return 0;
}