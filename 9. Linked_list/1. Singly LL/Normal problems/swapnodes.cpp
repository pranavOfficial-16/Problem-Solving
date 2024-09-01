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
Node* swapNodes(Node *head, int i, int j)
{
    if(head == NULL || head->next == NULL || i == j)
        return head;
    Node *temp = head;
    for (int count = 0; count < i && temp != NULL; count++)
        temp = temp->next;
    Node *swap1 = temp;
    temp = head;
    for (int count = 0; count < j && temp != NULL; count++)
        temp = temp->next;
    Node *swap2 = temp;
    int val = swap1->data;
    swap1->data = swap2->data;
    swap2->data = val;
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    return head;
}
int main()
{
    Node *head = input();
    int i, j;
    cin >> i >> j;
    head = swapNodes(head, i, j);
    print(head);
    return 0;
}