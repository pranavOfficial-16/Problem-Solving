#include "SingleLinkedListSyntax.cpp"
// iterative approach
int length(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
// recursive approach
/*
    int length(Node *head) {
        // base case
        if(head == NULL)
            return 0;
        else
            return 1 + length(head->next);
    }
*/
int main()
{
    Node *head = input();
    print(head);
    cout << "Length of Linked List -> " << length(head);
    return 0;
}