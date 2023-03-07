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
Node *evenAfterOdd(Node *head)
{
    if(head == NULL || head->next == NULL)
        return head;
    Node *current = head;
    Node *oddstart = NULL;
    Node *oddend = NULL;
    Node *evenstart = NULL;
    Node *evenend = NULL;
    while (current != NULL)
    {
        if (current->data % 2 == 1)
        {
            if (oddstart == NULL)
            {
                oddstart = current;
                oddend = current;
            }
            else
            {
                oddend->next = current;
                oddend = current;
            }
        }
        else
        {
            if (evenstart == NULL)
            {
                evenstart = current;
                evenend = current;
            }
            else
            {
                evenend->next = current;
                evenend = current;
            }
        }
        current = current->next;
    }
    if(oddstart == NULL || evenstart == NULL)
        return head;
    oddend->next = evenstart;
    evenend->next = NULL;
    head = oddstart;
    return head;
}
int main()
{
    Node *head = input();
    head = evenAfterOdd(head);
    print(head);
    return 0;
}