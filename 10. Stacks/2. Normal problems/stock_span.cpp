#include <bits/stdc++.h>
using namespace std;

/*
    Optimal
        TC -> O(2n)
        SC -> O(n)
*/
class StockSpanner
{
public:
    stack<pair<int, int>> st;
    int index = -1;
    void clear(stack<pair<int, int>> &st)
    {
        while (!st.empty())
        {
            st.pop();
        }
    }
    StockSpanner()
    {
        index = -1;
        clear(st);
    }

    int next(int price)
    {
        int ans;
        index++;
        while (!st.empty() && st.top().first <= price)
            st.pop();
        ans = index - (st.empty() ? -1 : st.top().second);
        st.push({price, index});
        return ans;
    }
};