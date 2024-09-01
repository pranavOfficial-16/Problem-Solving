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
Node *kReverse(Node *head, int k)
{
    if (k == 0)
        return head;
    Node *current = head;
    Node *before = NULL;
    Node *after = NULL;
    int count = 0;
    while (count < k && current != NULL)
    {
        after = current->next;
        current->next = before;
        before = current;
        current = after;
        count++;
    }
    if (after != NULL)
        head->next = kReverse(after, k);
    head = before;
    return head;
}

int main()
{
    Node *head = input();
    int k;
    cin >> k;
    head = kReverse(head, k);
    print(head);
    return 0;
}