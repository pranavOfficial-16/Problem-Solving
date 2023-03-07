// optimal approach - Sliding Window Technique
/*

************** Same approach with Sliding Window Technique **************

    char highestOccurringChar(string s)
    {
        int freq[26] = {0};
        for (int i = 0; i < s.size(); i++)
            freq[s[i] - 'a']++;
        char ans;
        int maxcount = 0;
        for (int i = 0; i < 26; i++)
        {
            if (freq[i] > maxcount)
            {
                maxcount = freq[i];
                ans = i + 'a';
            }
        }
        return ans;
    }

*/
#include<bits/stdc++.h>
using namespace std;
char highestOccurringChar(char a[])
{
    int n = strlen(a);
    int count[256] = {0};
    int max = 0;
    char result;
    for (int i = 0; i < n; i++)
    {
        count[a[i]]++;
        if (max <= count[a[i]])
        {
            max = count[a[i]];
            result = a[i];
        }
    }
    return result;
}
int main()
{
    char a[50];
    cin >> a;
    cout << highestOccurringChar(a);
    return 0;
}