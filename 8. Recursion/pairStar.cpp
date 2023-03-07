#include<iostream>
using namespace std;
void pairStar(char input[])
{
    string s = "";
    for (int i = 0; input[i] != '\0'; i++)
    {
        s += input[i];
        if (input[i] == input[i + 1])
            s += "*";
    }
    for (int i = 0; i < s.size() + 1; i++)
    {
        input[i] = s[i];
    }
}

int main()
{
    char input[100];
    cin.getline(input, 100);
    pairStar(input);
    cout << input << endl;
    return 0;
}