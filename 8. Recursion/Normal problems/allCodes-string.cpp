// Method-1 - using recursion ( return all codes-string )
// #include<bits/stdc++.h>
// using namespace std;
// void solve(string input, string out, vector<string> &str)
// {
//     if (input.size() == 0)
//     {
//         str.push_back(out);
//         return;
//     }
//     char c1 = (input[0] - 48) + 96;

//     // Ignore the output coming from zero in a string
//     if (input[0] == '0')
//         return;

//     solve(input.substr(1), out + c1, str);

//     if (input.size() > 1)
//     {
//         int d = (input[0] - 48) * 10 + (input[1] - 48);
//         if (d > 26)
//             return;
//         char c2 = 96 + d;
//         solve(input.substr(2), out + c2, str);
//     }
// }

// int getCodes(string input, string output[10000])
// {
//     vector<string> str;
//     string out = "";
//     solve(input, out, str);

//     for (int i = 0; i < str.size(); i++)
//         output[i] = str[i];

//     int x = str.size();

//     return x;
// }
// int main()
// {
//     string input;
//     cin >> input;

//     string output[10000];
//     int count = getCodes(input, output);
//     for (int i = 0; i < count && i < 10000; i++)
//         cout << output[i] << endl;
//     return 0;
// }

// Method-2 - using recursion ( print all the codes-string )
#include <bits/stdc++.h>
using namespace std;
void solve(string input, string out, vector<string> &str)
{
    if (input.size() == 0)
    {
        str.push_back(out);
        return;
    }
    char c1 = (input[0] - 48) + 96;

    // Ignore the output coming from zero in a string
    if (input[0] == '0')
        return;

    solve(input.substr(1), out + c1, str);

    if (input.size() > 1)
    {
        int d = (input[0] - 48) * 10 + (input[1] - 48);
        if (d > 26)
            return;
        char c2 = 96 + d;
        solve(input.substr(2), out + c2, str);
    }
}

void getCodes(string input)
{
    vector<string> str;
    string out = "";
    solve(input, out, str);
    string output[10000];
    int x = str.size();
    for (int i = 0; i < str.size(); i++)
        output[i] = str[i];
    for (int i = 0; i < str.size() && i < 10000; i++)
        cout << output[i] << endl;
}
int main()
{
    string input;
    cin >> input;
    getCodes(input);
    return 0;
}