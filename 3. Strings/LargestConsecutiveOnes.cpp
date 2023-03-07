// Given a binary string return the length of largest consecutive ones
#include <iostream>
using namespace std;
int consecutiveones(string s)
{
    int count = 0;
    int mx = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
            count = 0;
        else
        {
            count++;
            mx = max(mx, count);
        }
    }
    return mx;
}
int main()
{
    string s;
    cin >> s;
    cout << consecutiveones(s);
    return 0;
}