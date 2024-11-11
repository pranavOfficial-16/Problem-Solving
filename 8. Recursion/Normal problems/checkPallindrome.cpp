#include <bits/stdc++.h>
using namespace std;
bool checkPalindrome(char *a, int i, int j)
{
    // base case
    if (i > j)
        return true;

    if (a[i] != a[j])
        return false;
    else
        checkPalindrome(a, i + 1, j - 1);
}
int main()
{
    char a[50];
    cin >> a;
    if (checkPalindrome(a, 0, strlen(a) - 1))
        cout << "true";
    else
        cout << "false";
    return 0;
}