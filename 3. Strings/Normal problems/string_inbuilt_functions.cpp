#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s = "(()())(())";
    cout<<s.substr()<<endl;
    cout<<s.substr(1,4)<<endl;
    cout<<s.substr(7,2)<<endl;
    // if(s.substr(1,2)=="bb"){
    //     cout<<"hi"<<endl;
    //     cout << s.substr(1,2).length()<< endl;
    //     cout << s.substr(3)<< endl;
    // }
    return 0;
}