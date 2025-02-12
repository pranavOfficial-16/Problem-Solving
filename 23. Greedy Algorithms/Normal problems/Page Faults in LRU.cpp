#include <bits/stdc++.h>
using namespace std;
int pageFaults(int N, int C, int pages[])
{
    deque<int> dq;
    unordered_set<int> pageSet;
    int pageFaults = 0;

    for (int i = 0; i < N; i++)
    {
        if(pageSet.find(pages[i]) != pageSet.end()){
            auto it = find(dq.begin(), dq.end(), pages[i]);
            dq.erase(it);
            dq.push_front(pages[i]);
        }
        else{
            pageFaults++;

            if(dq.size() == C){
                int last = dq.back();
                dq.pop_back();
                pageSet.erase(last);
            }

            dq.push_front(pages[i]);
            pageSet.insert(pages[i]);
        }
    }
    return pageFaults;
}