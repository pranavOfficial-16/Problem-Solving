#include <iostream>
#include<cstring>
using namespace std;
void removeConsecutiveDuplicates(char a[])
{
    string s = "";
    int n = strlen(a);
    for (int i = 0; i < n; i++)
    {
        if (a[i] != a[i + 1])
            s += a[i];
    }
    for(int i=0;i<n;i++){
        a[i] = s[i];
    }
}
int main()
{
    char a[50];
    cin >> a;
    removeConsecutiveDuplicates(a);
    cout << a;
    return 0;
}