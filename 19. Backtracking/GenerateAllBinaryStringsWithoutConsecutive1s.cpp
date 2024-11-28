#include <bits/stdc++.h>
using namespace std;
vector<string> generateBinaryStrings(int num)
{
    vector<string> binaryStrings;
    generateBinaryStringsHelper("0", num, binaryStrings);
    generateBinaryStringsHelper("1", num, binaryStrings);
    return binaryStrings;
}
void static generateBinaryStringsHelper(string binaryString, int num, vector<string> &binaryStrings)
{
    int n = binaryString.size();

    // base case
    if (n == num)
    {
        binaryStrings.push_back(binaryString);
        return;
    }
    
    char lastAddedChar = binaryString[n - 1];

    generateBinaryStringsHelper(binaryString + "0", num, binaryStrings);
    if (lastAddedChar != '1')
        generateBinaryStringsHelper(binaryString + "1", num, binaryStrings);
}