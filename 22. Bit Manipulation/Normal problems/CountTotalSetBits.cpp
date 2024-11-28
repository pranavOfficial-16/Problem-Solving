#include <bits/stdc++.h>
using namespace std;
// brian kernighan's algorithm
int countSetBits(int n)
{
    int count = 0;
    for (int i = 1; i <= n; i++){
        int num = i;
        while(num){
            num = num & (num - 1);
            count++;
        }
    }
    return count;
}