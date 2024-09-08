#include "../Introduction/SingleLinkedListSyntax.cpp"

/*
    check if there is a loop and return the looplength
*/
int countNodesinLoop(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            int loopLength = 1;
            Node *temp = slow;
            while (temp->next != slow)
            {
                loopLength++;
                temp = temp->next;
            }
            return loopLength;
        }
    }
    return 0;
}