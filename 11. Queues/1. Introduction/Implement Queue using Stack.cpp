#include <bits/stdc++.h>
using namespace std;
class MyQueue
{
public:
    /*
        S1 -> S2
        X  -> S1
        S2 -> S1
    */
    stack<int> s1, s2;
    MyQueue() {}
    void push(int x)
    {
        while (s1.size())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (s2.size())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop()
    {
        int num = s1.top();
        s1.pop();
        return num;
    }

    int peek()
    {
        return s1.top();
    }

    bool empty()
    {
        return s1.empty();
    }
};