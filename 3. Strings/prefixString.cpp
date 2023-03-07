#include <iostream>
using namespace std;
void printPrefixes(char *input)
{
    for (int i = 0; input[i] != '\0'; i++)
    {
        for (int j = i; input[j] != '\0'; j++)
        {
            for (int k = i; k <= j; k++)
            {
                cout << input[k];
            }
            cout << endl;
        }
        cout << endl;
    }
}
int main()
{
    char str[50];
    cin.getline(str, 50);
    printPrefixes(str);
    return 0;
}