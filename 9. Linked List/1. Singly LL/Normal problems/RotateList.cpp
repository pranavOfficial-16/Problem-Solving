#include "../Introduction/SingleLinkedListSyntax.cpp"

Node *rotateRight(Node *head, int k)
{
    if (k == 0 || head == NULL)
        return head;

    int len = 1;
    Node *tail = head;
    while (tail->next != NULL)
    {
        len++;
        tail = tail->next;
    }
    // if its multiple of length
    if (k % len == 0)
        return head;

    k = k % len;
    tail->next = head;

    Node *temp = head;
    int count = 1;
    while (temp != NULL && count < len - k)
    {
        temp = temp->next;
        count++;
    }
    head = temp->next;
    temp->next = NULL;
    return head;
}