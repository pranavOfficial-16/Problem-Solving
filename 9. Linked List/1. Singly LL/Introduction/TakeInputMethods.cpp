#include "Node.cpp"

//  TC - O(n^2)
// Node *input()
// {
//     int data;
//     cin >> data;
//     Node *head = NULL;
//     while (data != -1)
//     {
//         Node *newNode = new Node(data);
//         if (head == NULL)
//             head = newNode;
//         else
//         {
//             Node *temp = head;
//             while (temp->next != NULL)
//                 temp = temp->next;
//             temp->next = newNode;
//         }
//         cin >> data;
//     }
//     return head;
// }

//  TC - O(n)
// Node *input()
// {
//     int data;
//     cin >> data;
//     Node *head = NULL;
//     Node *tail = NULL;
//     while (data != -1)
//     {
//         Node *newNode = new Node(data);
//         if (head == NULL)
//         {
//             head = newNode;
//             tail = newNode;
//         }
//         else
//         {
//             tail->next = newNode;
//             tail = newNode;
//         }
//         cin >> data;
//     }
//     return head;
// }

// More optimized TC - O(n)
Node *input()
{
    int data;
    Node *head = NULL;
    Node *tail = NULL;
    while (cin >> data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = input();
    print(head);
}