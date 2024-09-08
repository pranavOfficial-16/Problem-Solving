#include "../Introduction/DoubleLinkedListSyntax.cpp"

vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
{
    vector<pair<int, int>> pairsum;
    Node *start = head;
    Node *end = head;
    while (end->next != NULL)
        end = end->next;
    while (start != NULL && end != NULL && start != end && start->prev != end)
    {
        int sum = start->data + end->data;
        if (sum == target)
        {
            pairsum.push_back({start->data, end->data});
            start = start->next;
            end = end->prev;
        }
        else if (sum > target)
            end = end->prev;
        else
            start = start->next;
    }
    return pairsum;
}