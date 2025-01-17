#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
};
ListNode *mergeKLists(vector<ListNode *> &lists)
{
    priority_queue<int, vector<int>, greater<int>> pq;

    for (ListNode *list : lists)
    {
        while (list != NULL)
        {
            pq.push(list->val);
            list = list->next;
        }
    }

    ListNode *dummy = new ListNode(0);
    ListNode *curr = dummy;

    while (!pq.empty())
    {
        curr->next = new ListNode(pq.top());
        pq.pop();
        curr = curr->next;
    }

    return dummy->next;
}