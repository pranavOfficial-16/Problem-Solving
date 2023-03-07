#include <bits/stdc++.h>
using namespace std;
void transferStack(stack<int> &s1, stack<int> &s2)
{
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
}
void reverseStack(stack<int> &input, stack<int> &a)
{
    stack<int> b;
    transferStack(input,a);
    transferStack(a,b);
    transferStack(b,input);
}
int main()
{
    stack<int> input, extra;
    int size;
    cin >> size;

    for (int i = 0, val; i < size; i++)
    {
        cin >> val;
        input.push(val);
    }

    reverseStack(input, extra);

    while (!input.empty())
    {
        cout << input.top() << " ";
        input.pop();
    }
}