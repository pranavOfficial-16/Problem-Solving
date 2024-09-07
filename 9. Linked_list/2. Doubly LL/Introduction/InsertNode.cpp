#include "DoubleLinkedListSyntax.cpp"
Node *insertNode(Node *head, int i, int value)
{
    Node *newNode = new Node(value);
    Node *temp = head;
    if (i == 0)
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return head;
    }
    int count = 0;
    while (temp != NULL && count < i - 1)
    {
        temp = temp->next;
        count++;
    }

    // if inserting one after last node
    if (temp != NULL && temp->next == NULL)
    {
        temp->next = newNode;
        newNode->prev = temp;
        return head;
    }

    // if inserting inbetween the linked list
    if (temp != NULL)
    {
        newNode->next = temp->next;
        temp->next->prev = newNode;
        temp->next = newNode;
        newNode->prev = temp;
    }
    return head;
}
int main()
{
    Node *head = input();
    printLeftToRight(head);
    printRightToLeft(head);
    head = insertNode(head, 3, 99);
    printLeftToRight(head);
    printRightToLeft(head);
    return 0;
}