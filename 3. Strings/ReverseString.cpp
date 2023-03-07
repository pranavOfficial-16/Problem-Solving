#include <iostream>
#include <cstring>
using namespace std;
void reverseString(char str[]){
    int i=0,j=strlen(str)-1;
    char temp;
    while(i<j){
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}
int main()
{
    char str[50];
    cin.getline(str,50);
    reverseString(str);
    cout<<str;
    return 0;
}