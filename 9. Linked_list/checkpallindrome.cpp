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
Node *getmid(Node *head)
{
    int n = length(head);
    int mid = (n - 1) / 2;
    while (mid--)
        head = head->next;
    return head;
}
Node *getreverse(Node *head)
{
    Node *current = head;
    Node *before = NULL;
    Node *after = NULL;
    while (current != NULL)
    {
        after = current->next;
        current->next = before;
        before = current;
        current = after;
    }
    head = before;
    return head;
}
bool isPalindrome(Node *head)
{
    if (head == NULL)
        return true;
    Node *temp = getmid(head);
    Node *secondHead = temp->next;
    temp->next = NULL;
    secondHead = getreverse(secondHead);
    Node *firstList = head;
    Node *secondList = secondHead;
    while (secondList != NULL)
    {
        if (firstList->data != secondList->data)
            return false;
        firstList = firstList->next;
        secondList = secondList->next;
    }
    return true;
}
int main()
{
    Node *head = input();
    bool ans = isPalindrome(head);
    if (ans)
        cout << "true";
    else
        cout << "false";
    return 0;
}