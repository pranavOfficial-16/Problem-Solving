#include<iostream>
using namespace std;
bool checkPalindrome(char *a){
    static int i = 0;
    int c = 0;
    while (a[c] != '\0')
    {
        c++;
    }
    static int d = c;
    if (a[i] == a[d - 1] && i < d)
    {
        i++;
        d--;
        return checkPalindrome(a);
    }
    else
    {
        if (i < d)
            return false;
        else
            return true;
    }
}
int main()
{
    char a[50];
    cin>>a;
    if(checkPalindrome(a))
        cout<<"true";
    else
        cout<<"false";
    return 0;
}