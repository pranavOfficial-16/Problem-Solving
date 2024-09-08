#include "../Introduction/SingleLinkedListSyntax.cpp"

// detect whether there exist a loop in a single linked list and return the pos node
Node *detectCycle(Node *head)
{
    Node *temp = head;
    map<Node *, int> visited;
    Node *pos = temp;
    while (temp != NULL)
    {
        if (visited.find(temp) != visited.end())
        {
            pos = temp;
            break;
        }
        visited[temp]++;
        temp = temp->next;
    }
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return pos;
    }
    return NULL;
}