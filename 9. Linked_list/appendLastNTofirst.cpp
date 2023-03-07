#include <bits/bits-stdc++.h>
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
int length(Node *head)
{
    // base case
    if (head == NULL)
        return 0;
    else
        return 1 + length(head->next);
}
Node *appendLastNToFirst(Node *head, int n)
{
    if (n == 0)
        return head;
    if (head == NULL)
        return NULL;
    Node *current = head;
    Node *prev = head;
    int count = length(head);
    int skip = count - n;
    while (skip > 0)
    {
        prev = current;
        current = current->next;
        skip--;
    }
    prev->next = NULL;
    Node *tail = current;
    while (tail->next != NULL)
        tail = tail->next;
    tail->next = head;
    head = current;
    return head;
}
int main()
{
    Node *head = input();
    int n;
    cin >> n;
    head = appendLastNToFirst(head, n);
    print(head);
    return 0;
}