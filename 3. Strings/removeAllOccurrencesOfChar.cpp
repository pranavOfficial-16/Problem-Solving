#include <iostream>
#include <cstring>
using namespace std;
void removeAllOccurrencesOfChar(char a[], char c)
{
    string s = "";
    int n = strlen(a);
    for (int i = 0; i < n; i++)
    {
        if (a[i] != c)
            s += a[i];
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = s[i];
    }
}

int main()
{
    char a[50];
    cin >> a;
    char c;
    cin>>c;
    removeAllOccurrencesOfChar(a,c);
    cout << a;
    return 0;
}