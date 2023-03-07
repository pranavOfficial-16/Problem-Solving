// Subsequences ( important )
// Subsequences are basically for strings

// method-1 - using recursion and backtracking ( return subsequences )
// #include <bits/stdc++.h>
// using namespace std;
// void solve(string str, string output, int index, vector<string> &ans)
// {
//     // base case
//     if (index >= str.size())
//     {
//         if (output.length() > 0)
//             ans.push_back(output);
//         return;
//     }
//     // exclude
//     solve(str, output, index + 1, ans);
//     // include
//     output.push_back(str[index]);
//     solve(str, output, index + 1, ans);
// }
// vector<string> subsequences(string str)
// {
//     vector<string> ans;
//     string output = "";
//     int index = 0;
//     solve(str, output, index, ans);
//     return ans;
// }
// int main()
// {
//     string str;
//     cin >> str;
//     vector<string> s = subsequences(str);
//     for (string x : s)
//     {
//         cout << x << endl;
//     }
//     return 0;
// }

// method-2 - using recursion ( print all the subsequences )
// #include <iostream>
// using namespace std;
// void print_subs(string input, string output)
// {
//     // base case
//     if (input.size() == 0)
//     {
//         cout << output << endl;
//         return;
//     }

//     // exclude
//     print_subs(input.substr(1), output);

//     // include
//     print_subs(input.substr(1), output + input[0]);
// }
// int main()
// {
//     string input;
//     cin >> input;
//     string output = "";
//     print_subs(input, output);
//     return 0;
// }

// method-3 - with recursion ( return subsequences )
#include <iostream>
using namespace std;
int subs(string input, string output[])
{
    // base case
    if (input.size() == 0)
    {
        output[0] = "";
        return 1;
    }
    int smalloutputsize = subs(input.substr(1), output);
    for (int i = 0; i < smalloutputsize; i++)
        output[i + smalloutputsize] = input[0] + output[i];
    return 2 * smalloutputsize;
}
int main()
{
    string input;
    cin >> input;
    string *output = new string[1000];
    int count = subs(input, output);
    for (int i = 0; i < count; i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}