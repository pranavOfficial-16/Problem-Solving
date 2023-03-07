// check if two strings are anagram or not
#include<iostream>
using namespace std;
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
int main()
{
    string a,b;
    cin>>a>>b;
    isAnagram(a,b)?cout<<"YES":cout<<"NO";
    return 0;
}