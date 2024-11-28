// Inbuilt priority Queue is by-default Max priority Queue
#include<bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int> p;
    
    p.push(100);
    p.push(21);
    p.push(7);
    p.push(165);
    p.push(78);
    p.push(4);

    cout << p.size() << endl;
    cout << p.empty() << endl;
    cout << p.top() << endl;

    while (!p.empty())
    {
        cout << p.top() << endl;
        p.pop();
    }
    
    return 0;
}