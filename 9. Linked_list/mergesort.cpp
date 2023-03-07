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
void splitList(Node *head, Node **a, Node **b)
{
    Node *slow = head;
    Node *fast = head->next;
    while (fast != nullptr)
    {
        fast = fast->next;
        if (fast != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    *a = head;
    *b = slow->next;
    slow->next = nullptr;
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
Node *mergeSort(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *temp = head;
    Node *a;
    Node *b;
    splitList(temp, &a, &b);
    a = mergeSort(a);
    b = mergeSort(b);
    return mergeTwoSortedLinkedLists(a, b);
}
int main()
{
    Node *head = input();
    head = mergeSort(head);
    print(head);
    return 0;
}