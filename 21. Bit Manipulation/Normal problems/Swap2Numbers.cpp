#include <bits/stdc++.h>
using namespace std;
pair<int, int> get(int a, int b)
{
    // approach 1 -> with 3rd variable
    // int temp = a;
    // a = b;
    // b = temp;
    // return {a, b};

    // approach 2 -> without 3rd variable
    // a = a + b;
    // b = a - b;
    // a = a - b;
    // return {a, b};

    // approach 3 -> using xor property
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    return {a, b};
}
int main()
{
    int a, b;
    cin >> a >> b;
    pair<int, int> p = get(a, b);
    cout << p.first << " " << p.second;
}