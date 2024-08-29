#include <iostream>
using namespace std;
void replaceCharacter(char input[], char c1, char c2)
{
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == c1)
            input[i] = c2;
    }
}
int main()
{
    char str[10];
    cin >> str;
    char c1,c2;
    cin>>c1>>c2;
    replaceCharacter(str,c1,c2);
    cout<<str;
    return 0;
}