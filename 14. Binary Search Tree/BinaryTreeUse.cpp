#include <bits/stdc++.h>
#include "BinaryTreeNode.h"
using namespace std;
BinaryTreeNode<int> *takeInputLevelWise()
{
    int rootData;
    cout << "Enter rootdata : " << endl;
    cin >> rootData;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size())
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter left child of " << front->data << endl;
        int leftChildData;
        cin >> leftChildData;
        if (leftChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        }
        cout << "Enter Right child of " << front->data << endl;
        int rightChildData;
        cin >> rightChildData;
        if (rightChildData != -1)
        {
            BinaryTreeNode<int> *child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        }
    }
    return root;
}
void printLevelWise(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size())
    {
        BinaryTreeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ":";
        if (front->left)
        {
            pendingNodes.push(front->left);
            cout << "L:" << front->left->data;
        }
        else
            cout << "L:-1";
        cout << ",";
        if (front->right)
        {
            pendingNodes.push(front->right);
            cout << "R:" << front->right->data;
        }
        else
            cout << "R:-1";
        cout << endl;
    }
}
// Search in BST
bool searchInBST(BinaryTreeNode<int> *root, int k)
{
    if (root == NULL)
        return false;
    if (root->data == k)
        return true;
    if (k > root->data)
        return searchInBST(root->right, k);
    if (k < root->data)
        return searchInBST(root->left, k);
}
// Print Elements in Range
void elementsInRangeK1K2(BinaryTreeNode<int> *root, int k1, int k2)
{
    if (root == NULL)
        return;
    if (k1 < root->data)
        elementsInRangeK1K2(root->left, k1, k2);
    if (root->data >= k1 && root->data <= k2)
        cout << root->data << " ";
    if (k2 > root->data)
        elementsInRangeK1K2(root->right, k1, k2);
}
// Check if a Binary Tree is BST
// approach 1
class Pair
{
public:
    int minimum;
    int maximum;
    bool check;
};
Pair solve(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        Pair p;
        p.minimum = INT_MAX;
        p.maximum = INT_MIN;
        p.check = true;
        return p;
    }
    Pair left = solve(root->left);
    Pair right = solve(root->right);
    Pair p;
    p.minimum = min(root->data, left.minimum);
    p.maximum = max(root->data, right.maximum);
    p.check = (root->data > left.maximum) && (root->data < right.minimum) && left.check && right.check;
    return p;
}
bool isBST(BinaryTreeNode<int> *root)
{
    return solve(root).check;
}

// Check if a Binary Tree is BST
// approach 2
BinaryTreeNode<int> *findMin(BinaryTreeNode<int> *node)
{
    if (node == NULL)
        return NULL;
    if (node->left == NULL)
        return node;
    return findMin(node->left);
}
BinaryTreeNode<int> *findMax(BinaryTreeNode<int> *node)
{
    if (node == NULL)
        return NULL;
    if (node->right == NULL)
        return node;
    return findMax(node->right);
}
bool isValidBST(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return true;
    BinaryTreeNode<int> *leftmax = findMax(root->left);
    BinaryTreeNode<int> *rightmin = findMin(root->right);

    if ((leftmax && root->data <= leftmax->data) ||
        (rightmin && root->data >= rightmin->data))
        return false;

    return isValidBST(root->left) && isValidBST(root->right);
}

// Construct BST from a Sorted Array
BinaryTreeNode<int> *solve(int *arr, int start, int end)
{
    if (start > end)
        return NULL;
    int mid = (start + end) / 2;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(arr[mid]);
    root->left = solve(arr, start, mid - 1);
    root->right = solve(arr, mid + 1, end);
    return root;
}
BinaryTreeNode<int> *constructTree(int *arr, int n)
{
    return solve(arr, 0, n - 1);
}
// Inorder traversal
void inorder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
//  BST to Sorted LL
template <typename T>
class Node
{
public:
    T data;
    Node *next;
    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};
void solve(vector<int> &v, BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    solve(v, root->left);
    v.push_back(root->data);
    solve(v, root->right);
}
Node<int> *constructLinkedList(BinaryTreeNode<int> *root)
{
    vector<int> v;
    solve(v, root);
    Node<int> *head = NULL;
    Node<int> *tail = NULL;
    for (int i : v)
    {
        Node<int> *newnode = new Node<int>(i);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    }
    return head;
}
// Find Path in BST
vector<int> *getPath(BinaryTreeNode<int> *root, int data)
{
    if (root == NULL)
        return NULL;

    if (root->data == data)
    {
        vector<int> *output = new vector<int>();
        output->push_back(root->data);
        return output;
    }

    vector<int> *leftOutput = getPath(root->left, data);
    if (leftOutput != NULL)
    {
        leftOutput->push_back(root->data);
        return leftOutput;
    }

    vector<int> *rightOutput = getPath(root->right, data);
    if (rightOutput != NULL)
    {
        rightOutput->push_back(root->data);
        return rightOutput;
    }
    else
        return NULL;
}
// Largest BST
struct LargestBST
{
    int minimum;
    int maximum;
    int height;
    bool check;
};
LargestBST verify(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        LargestBST ob;
        ob.minimum = INT_MAX;
        ob.maximum = INT_MIN;
        ob.height = 0;
        ob.check = true;
        return ob;
    }
    LargestBST left = verify(root->left);
    LargestBST right = verify(root->right);
    if (!(left.check && left.maximum < root->data))
        left.check = false;
    if (!(right.check && right.minimum > root->data))
        right.check = false;
    if (!left.check || !right.check || root->data > right.minimum || root->data < left.maximum)
    {
        if (left.height > right.height)
        {
            left.check = false;
            return left;
        }
        else
        {
            right.check = false;
            return right;
        }
    }
    LargestBST ob;
    ob.check = true;
    ob.minimum = min(left.minimum, min(root->data, right.minimum));
    ob.maximum = max(left.maximum, max(root->data, right.maximum));
    ob.height = max(left.height, right.height) + 1;
    return ob;
}
int largestBSTSubtree(BinaryTreeNode<int> *root)
{
    return verify(root).height;
}
// Replace with Sum of greater nodes
int solve(BinaryTreeNode<int> *root, int sum)
{
    if (root == NULL)
        return sum;
    sum = solve(root->right, sum);
    sum += root->data;
    root->data = sum;
    sum = solve(root->left, sum);
    return sum;
}
void replaceWithLargerNodesSum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    int ans = solve(root, 0);
}
// 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1 2
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printLevelWise(root);
    cout << searchInBST(root, 2) << endl;
    inorder(root);
    return 0;
}