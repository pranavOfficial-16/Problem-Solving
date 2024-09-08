#include "SingleLinkedListSyntax.cpp"
Node *insertNode(Node *head, int i, int value)
{
    Node *newnode = new Node(value);
    int count = 0;
    Node *temp = head;
    if (i == 0)
    {
        newnode->next = head;
        head = newnode;
        return head;
    }
    while (temp != NULL && count < i - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp != NULL)
    {
        newnode->next = temp->next;
        temp->next = newnode;
    }
    return head;
}
// recursive insert node in the linked list
/*
    Node* insertNode(Node *head, int i, int data) {
        // base case
        if(head==NULL)
            return NULL;
        if(i==0){
            Node *newNode=new Node(data);
            newNode->next=head;
            return newNode;
        }
        if(i==1){
            Node *newNode=new Node(data);
            newNode->next=head->next;
            head->next=newNode;
            return head;
        }
        Node* current = insertNode(head->next,i-1,data);
        return head;
    }
*/
int main()
{
    Node *head = input();
    int i, value;
    cin >> i >> value;
    cout << "OLD LIST -> ";
    print(head);
    head = insertNode(head, i, value);
    cout << endl;
    cout << "NEW LIST -> ";
    print(head);
    return 0;
}