#include "../Introduction/SingleLinkedListSyntax.cpp"

Node *reverse(Node *head)
{
    Node *current = head;
    Node *before = NULL;
    Node *after = NULL;
    while (current != NULL)
    {
        after = current->next;
        current->next = before;
        before = current;
        current = after;
    }
    head = before;
    return head;
}
Node *addOne(Node *head)
{
    Node *rev = reverse(head);
    Node *temp = rev;
    int carry = 1;
    while (temp != NULL)
    {
        int sum = temp->data + carry;
        carry = sum / 10;
        temp->data = sum % 10;
        if (carry == 0)
            break;
        if (temp->next == NULL && carry > 0)
        {
            temp->next = new Node(carry);
            carry = 0;
        }
        temp = temp->next;
    }
    return reverse(rev);
}