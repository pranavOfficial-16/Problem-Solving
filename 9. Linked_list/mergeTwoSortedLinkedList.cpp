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
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
Node *mergeTwoSortedLinkedLists(Node *h1, Node *h2)
{
    if (h1 == NULL)
        return h2;
    else if (h2 == NULL)
        return h1;
    Node *finalhead = NULL;
    if (h1->data <= h2->data)
    {
        finalhead = h1;
        h1 = h1->next;
    }
    else
    {
        finalhead = h2;
        h2 = h2->next;
    }
    Node *finaltail = finalhead;
    while (h1 != NULL && h2 != NULL)
    {
        if (h1->data <= h2->data)
        {
            finaltail->next = h1;
            finaltail = h1;
            h1 = h1->next;
        }
        else
        {
            finaltail->next = h2;
            finaltail = h2;
            h2 = h2->next;
        }
    }
    if (h1 == NULL)
        finaltail->next = h2;
    else
        finaltail->next = h1;
    return finalhead;
}
int main()
{
    Node *h1 = input();
    Node *h2 = input();
    Node *head = mergeTwoSortedLinkedLists(h1,h2);
    print(head);
    return 0;
}