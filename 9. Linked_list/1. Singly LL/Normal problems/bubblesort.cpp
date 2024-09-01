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
int len(Node *head)
{
    Node *temp = head;
    int i = 0;
    while (temp != NULL)
    {
        i++;
        temp = temp->next;
    }

    return i;
}
Node *swap(Node *ptr1, Node *ptr2)
{
    Node *tmp = ptr2->next;
    ptr2->next = ptr1;
    ptr1->next = tmp;
    return ptr2;
}

Node *bubbleSort(Node **head)
{
    int length = len(*head);
    Node **temp;
    int i, j, swapped;
    Node *p1, *p2;

    for (i = 0; i <= length; i++)
    {

        temp = head;
        swapped = 0;

        for (j = 0; j < length - i - 1; j++)
        {

            p1 = *temp;
            p2 = p1->next;

            if (p1->data > p2->data)
            {
                /* update the link after swapping */
                *temp = swap(p1, p2);
                swapped = 1;
            }

            temp = &(*temp)->next;
        }

        if (swapped == 0)
            break;
    }
    return *head;
}
Node *bubbleSort(Node *head)
{
    return bubbleSort(&head);
}
int main()
{
    Node *head = input();
    head = bubbleSort(head);
    print(head);
    return 0;
}