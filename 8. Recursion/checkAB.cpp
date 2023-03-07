#include <string>
#include <iostream>
using namespace std;
bool checkAB(string &s)
{
    string value;
    // base case
    if (s.empty())
    {
        return true;
    }
    if (s[0] == 'a')
    {
        if (s.substr(1).length() > 1 && s.substr(1,2) == "bb")
        {
            value = s.substr(3);
            return checkAB(value);
        }
        else
        {
            value = s.substr(1);
            return checkAB(value);
        }
    }
    return false;
}
bool checkAB(char input[])
{
    string s = input;
    bool checkoutput = checkAB(s);
    return checkoutput;
}

int main()
{
    char input[50];
    cin>>input;
    checkAB(input)?cout<<"true":cout<<"false";
    return 0;
}