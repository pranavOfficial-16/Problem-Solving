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
// iterative approach
int findNode(Node *head, int n)
{
    Node *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        if (temp->data == n)
            return count - 1;
        temp = temp->next;
    }
    return -1;
}
// recursive approach
/*
    int findNodeRec(Node *head, int n)
    {
        int smallans;
        if(head == NULL)
            return -1;
        if(head->data == n)
            return 0;
        if(head->data != n){
            smallans = findNodeRec(head->next,n);
            if(smallans == -1)
                return -1;
            else
                return 1 + smallans;
        }
    }
*/
int main()
{
    Node *head = input();
    int n;
    cin >> n;
    cout << findNode(head, n);
    return 0;
}