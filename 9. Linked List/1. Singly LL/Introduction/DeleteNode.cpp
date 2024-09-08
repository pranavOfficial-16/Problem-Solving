#include "SingleLinkedListSyntax.cpp"
Node *deleteNode(Node *head, int i)
{
    // If linked list is null
    if (head == NULL)
        return NULL;

    int count = 0;
    Node *before = head;

    // If ith node is zero
    if (i == 0)
    {
        Node *newnode = head->next;
        head = newnode;
        return head;
    }

    // If the ith node is out of bound
    int length = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    if (i >= length)
        return head;

    // If the ith node lies in the linked list
    while (before != NULL && count < i - 1)
    {
        before = before->next;
        count++;
    }
    if (before != NULL)
    {
        Node *current = before->next;
        Node *after = current->next;
        before->next = after;
        delete current;
    }

    return head;
}
// recursive delete node in the linked list
/*
    Node* deleteNode(Node *head, int i)
    {
        if (head == NULL || i < 0)
            return head;
        if (i == 0)
        {
            Node *p = head;
            head = p->next;
            delete p;
            return head;
        }
        Node *x = deleteNode(head->next, i - 1);
        head->next = x;
        x = head;
        return head;
    }
*/
int main()
{
    Node *head = input();
    int i;
    cin >> i;
    cout << "OLD LIST -> ";
    print(head);
    head = deleteNode(head, i);
    cout << endl;
    cout << "NEW LIST -> ";
    print(head);
    return 0;
}