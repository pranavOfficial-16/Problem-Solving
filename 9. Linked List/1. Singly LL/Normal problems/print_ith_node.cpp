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
void printIthNode(Node *head, int i)
{
    int count = 0;
    Node *temp = head;
    if (i == 0)
        cout << temp->data;
    else
    {
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
            if (count == i)
            {
                cout << temp->data;
                break;
            }
        }
    }
}
int main()
{
    Node *head = input();
    int i;
    cin >> i;
    printIthNode(head, i);
    return 0;
}