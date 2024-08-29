// check if two strings are anagram or not
#include <iostream>
using namespace std;
// Note - both the methods are same. Just a small alteration way
// method - 1
bool isAnagram(string a, string b)
{
    if (a.size() != b.size())
        return false;
    int count1[256] = {0};
    int count2[256] = {0};
    for (int i = 0; i < a.size(); i++)
    {
        count1[a[i]]++;
        count2[b[i]]++;
    }
    for (int i = 0; i < 256; i++)
    {
        if (count1[i] != count2[i])
            return false;
    }
    return true;
}

// method - 2
bool isAnagram(string s, string t)
{

    if (s.size() != t.size())
        return false;

    int arr[26] = {0};

    // store s count
    for (int i = 0; i < s.size(); i++)
        arr[s[i] - 'a']++;

    // store t count
    for (int i = 0; i < s.size(); i++)
        arr[t[i] - 'a']--;

    // compare now
    for (int i = 0; i < 26; i++)
    {
        if (arr[i] != 0)
            return false;
    }
    return true;
}
int main()
{
    string a, b;
    cin >> a >> b;
    isAnagram(a, b) ? cout << "YES" : cout << "NO";
    return 0;
}