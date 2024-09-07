#include "../Introduction/SingleLinkedListSyntax.cpp"

Node *reverseKGroup(Node *head, int k)
{
    if (k <= 0 || head == NULL)
        return head;

    // Check if there are at least k nodes to reverse
    Node *temp = head;
    int count = 0;
    while (count < k && temp != NULL)
    {
        temp = temp->next;
        count++;
    }

    // If there are fewer than k nodes, return head as is
    if (count < k)
        return head;

    // Reverse k nodes
    Node *current = head;
    Node *before = NULL;
    Node *after = NULL;
    count = 0;
    while (count < k && current != NULL)
    {
        after = current->next;
        current->next = before;
        before = current;
        current = after;
        count++;
    }

    // Connect the reversed part with the next part
    if (after != NULL)
        head->next = reverseKGroup(after, k);

    return before; 
}