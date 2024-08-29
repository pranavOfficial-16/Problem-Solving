#include <iostream>
using namespace std;
int main()
{
    char c;
    int countchar = 0, countdigits = 0, countspaces = 0;
    c = cin.get();
    while (c != '$')
    {
        if (c >= 'a' && c <= 'z')
            countchar++;
        else if (isdigit(c))
            countdigits++;
        else if (c == ' ' || c == '\n' || c == '\t')
            countspaces++;
        c = cin.get();
    }
    cout << countchar << " " << countdigits << " " << countspaces;
    return 0;
}
