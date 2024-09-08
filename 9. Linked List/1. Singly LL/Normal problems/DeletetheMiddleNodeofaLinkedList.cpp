#include "../Introduction/SingleLinkedListSyntax.cpp"

// bruteforce
// TC-> O(n) + O(n/2), SC-> O(1)
int length(Node *head)
{
    // base case
    if (head == NULL)
        return 0;
    else
        return 1 + length(head->next);
}
Node *deleteMiddle1(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    int n = length(head);
    int midnode = (n / 2) + 1;
    Node *temp = head;
    while (temp != NULL)
    {
        midnode--;
        if (midnode == 0)
        {
            Node *middle = temp->next;
            temp->next = temp->next->next;
            delete middle;
            break;
        }
        temp = temp->next;
    }
    return head;
}

// Optimal
// TC-> O(n), SC-> O(1)
Node *deleteMiddle1(Node *head)
{
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *slow = head;
    Node *fast = head;
    fast = fast->next->next;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    slow->next = slow->next->next;
    return head;
}