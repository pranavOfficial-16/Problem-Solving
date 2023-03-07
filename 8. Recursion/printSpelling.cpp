#include <iostream>
using namespace std;
void printSpelling(string *s, int n)
{
    if (n == 0)
        return;
    printSpelling(s, n / 10);
    cout << s[n % 10] << " ";
}
int main()
{
    int n;
    cin >> n;
    string s[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    printSpelling(s, n);
    return 0;
}