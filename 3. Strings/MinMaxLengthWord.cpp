#include <iostream>
#include <cstring>
#include <limits.h>
using namespace std;
void minLengthWord(char *a)
{
    string result,s = "";
    int n = strlen(a), mi = INT_MAX, count = 0;
    a[n] = ' ';
    for (int i = 0; i < n + 1; i++)
    {
        if (a[i] != ' ')
        {
            count++;
            s += a[i];
        }
        else
        {
            if (count < mi)
            {
                mi = count;
                result = s;
            }
            s = "";
            count = 0;
        }
    }
    cout << "Min Length Word : " << result;
}
void maxLengthWord(char *a)
{
    string result, s = "";
    int n = strlen(a), mx = INT_MIN, count = 0;
    a[n] = ' ';
    for (int i = 0; i < n + 1; i++)
    {
        if (a[i] != ' ')
        {
            count++;
            s += a[i];
        }
        else
        {
            if (count > mx)
            {
                mx = count;
                result = s;
            }
            s = "";
            count = 0;
        }
    }
    cout << "Max Length Word : " << result;
}
int main()
{
    char a[100];
    cin.getline(a, 100);
    minLengthWord(a);
    cout<<endl;
    maxLengthWord(a);
    return 0;
}