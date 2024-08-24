#include <bits/stdc++.h>
using namespace std;
void trimSpaces(char input[])
{
    int n = strlen(input);
    char s[n];
    for (int i = 0; i < n; i++)
        s[i] = input[i];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != ' ')
            input[j++] = s[i];
    }
    input[j] = '\0';
}
int main()
{
    char input[20];
    cin.getline(input, 20);
    trimSpaces(input);
    cout << input;
    return 0;
}