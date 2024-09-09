#include<iostream>
using namespace std;
void removeConsecutiveDuplicates(char *s)
{
    if (s[0] == '\0')
        return;
    if (s[0] == s[1])
    {
        int i = 1;
        for (; s[i] != '\0'; i++)
            s[i - 1] = s[i];
        s[i - 1] = s[i];
        removeConsecutiveDuplicates(s);
    }
    removeConsecutiveDuplicates(s + 1);
}
int main()
{
    char s[100];
    cin >> s;
    removeConsecutiveDuplicates(s);
    cout << s << endl;
    return 0;
}