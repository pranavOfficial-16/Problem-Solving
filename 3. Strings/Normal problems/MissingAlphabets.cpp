// print the missing alphabets from a given string
#include <bits/stdc++.h>
using namespace std;
string missingChars(string str)
{
    bool present[26] = {false};
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            present[str[i] - 'a'] = true;
        else if (str[i] >= 'A' && str[i] <= 'Z')
            present[str[i] - 'A'] = true;
    }
    string res = "";
    for (int i = 0; i < 26; i++)
        if (present[i] == false)
            res.push_back((char)(i + 'a'));

    return res;
}
int main()
{
    string str;
    getline(cin, str);
    cout << missingChars(str);
    return 0;
}
