#include "../Introduction/DoubleLinkedListSyntax.cpp"
Node *reverseDLL(Node *head)
{
    Node *current = head;
    Node *before = NULL;
    Node *after = NULL;
    while (current != NULL)
    {
        after = current->next;
        current->prev = after;
        current->next = before;
        before = current;
        current = after;
    }
    head = before;
    return head;
}