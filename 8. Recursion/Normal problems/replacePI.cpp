#include<bits/stdc++.h>
using namespace std;
void replacePi(char input[])
{
    if (input[0] == '\0')
        return;
    if (input[0] == 'p' && input[1] == 'i')
    {
        input[0] = '3';
        input[1] = '.';

        int size = strlen(input);
        for (int i = size + 2; i > 1; i--)
            input[i] = input[i - 2];
        input[2] = '1';
        input[3] = '4';
    }
    replacePi(input + 1);
}
int main()
{
    char input[100];
    cin.getline(input, 100);
    replacePi(input);
    cout << input << endl;
    return 0;
}