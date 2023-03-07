#include <iostream>
using namespace std;
int length(char s[])
{
    if (s[0] == '\0')
        return 0;
    return 1 + length(s+1);
}
int main()
{
    char s[50];
    cin >> s;
    int l = length(s);
    cout << l << endl;
    return 0;
}