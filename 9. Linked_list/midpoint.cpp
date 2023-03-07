#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
Node *input()
{
    int data;
    cin >> data;
    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *newnode = new Node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}
int length(Node *head)
{
    // base case
    if (head == NULL)
        return 0;
    else
        return 1 + length(head->next);
}
Node *midPoint(Node *head)
{
    int n = length(head);
    int mid = (n - 1) / 2;
    while (mid--)
        head = head->next;
    return head;
}
int main()
{
    Node *head = input();
    head = midPoint(head);
    cout << head->data;
    return 0;
}