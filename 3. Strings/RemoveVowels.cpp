#include <bits/stdc++.h>
using namespace std;
bool notvowel(char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return false;
    else
        return true;
}
string removeVowels(char str[], int n)
{
    for (int i = 0; i < n; i++)
        str[i] = tolower(str[i]);
    string ans;
    for (int i = 0; i < n; i++)
    {
        if (notvowel(str[i]))
            ans += str[i];
    }
    return ans;
}
int main()
{
    char str[50];
    cin.getline(str, 50);
    cout << removeVowels(str, strlen(str));
    return 0;
}