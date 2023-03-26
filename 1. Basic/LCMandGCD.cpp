/*
    H.C.F. of Two numbers = Product of Two numbers/L.C.M of two numbers
    L.C.M  of two numbers = Product of Two numbers/H.C.F. of Two numbers
*/
#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
vector<long long> lcmandgcd(long long a, long long b)
{
    long long hcf = gcd(a, b);
    long long lcm = (a * b) / hcf;
    return {lcm, hcf};
}
int main()
{
    long long a, b;
    cin >> a >> b;
    vector<long long> v = lcmandgcd(a, b);
    for (auto i : v)
        cout << i << " ";
    return 0;
}