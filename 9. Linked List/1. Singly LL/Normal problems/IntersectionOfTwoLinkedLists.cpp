#include "../Introduction/SingleLinkedListSyntax.cpp"

Node *getIntersectionNode(Node *headA, Node *headB)
{
    map<Node *, bool> mpp; // map to store visited nodes

    // Traverse list A and store each node in the map
    while (headA != NULL)
    {
        mpp[headA] = true;
        headA = headA->next;
    }

    // Traverse list B and check if any node is already in the map
    while (headB != NULL)
    {
        if (mpp.find(headB) != mpp.end())
        {
            // Intersection found
            return headB;
        }
        headB = headB->next;
    }

    // No intersection found
    return NULL;
}