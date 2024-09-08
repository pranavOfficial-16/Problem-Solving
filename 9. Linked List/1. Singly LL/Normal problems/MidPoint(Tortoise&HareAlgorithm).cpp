#include "../Introduction/SingleLinkedListSyntax.cpp"

int length(Node *head)
{
    // base case
    if (head == NULL)
        return 0;
    else
        return 1 + length(head->next);
}
// bruteforce-1
Node *midPoint1(Node *head)
{
    int n = length(head);
    int mid;
    if (n % 2 == 1) // odd length
        mid = (n - 1) / 2;
    else
        mid = n / 2; // even length
    while (mid--)
        head = head->next;
    return head;
}
// bruteforce-2
Node *midPoint2(Node *head)
{
    int n = length(head);
    int midnode = (n / 2) + 1;
    Node *temp = head;
    while (temp != NULL)
    {
        midnode--;
        if (midnode == 0)
            break;
        temp = temp->next;
    }
    return temp;
}

// Optimal
// tortoise & hare algorithm - fast and slow pointer
Node *midPoint3(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}