#include<iostream>
#include <cstring>
using namespace std;
bool checkPalindrome(char str[])
{
    int n = strlen(str);
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != str[n - i - 1])
            return false;
    }
    return true;
}
int main()
{
    char str[10];
    cin>>str;
    cout<<(checkPalindrome(str))?"true":"false";
    return 0;
}