#include <iostream>
#include <cstring>
using namespace std;
void reverseString(char str[], int i, int j)
{
    char temp;
    while (i < j)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}
void reverseStringWordWise(char str[])
{
    int start = 0, n = strlen(str);
    for (int end = 0; end < n; end++)
    {
        if (str[end] == ' ')
        {
            reverseString(str, start, end-1);
            start = end+1;
        }
    }
    reverseString(str,start,n-1);
    reverseString(str, 0, n - 1);
}
int main()
{
    char str[50];
    cin.getline(str, 50);
    reverseStringWordWise(str);
    cout << str;
    return 0;
}