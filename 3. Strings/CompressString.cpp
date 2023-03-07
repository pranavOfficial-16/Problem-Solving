#include <iostream>
#include <string>
using namespace std;
string getCompressedString(string &s)
{
    int count[256] = {0};
    string result = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == s[i + 1])
        {
            count[s[i]]++;
        }
        else
        {
            count[s[i]]++;
            if (count[s[i]] == 1)
                result = result + s[i];
            else
                result = result + s[i] + to_string(count[s[i]]);
            count[s[i]] = 0;
        }
    }
    return result;
}
int main()
{
    string input;
    cin >> input;
    cout << getCompressedString(input);
    return 0;
}