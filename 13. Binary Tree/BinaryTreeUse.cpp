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
int numNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    return 1 + numNodes(root->left) + numNodes(root->right);
}
bool isNodePresent(BinaryTreeNode<int> *root, int x)
{
    if (root == NULL)
        return false;
    if (root->data == x)
        return true;
    if (isNodePresent(root->left, x))
        return true;
    if (isNodePresent(root->right, x))
        return true;
    else
        return false;
}
int height(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int leftdepth = height(root->left);
    int rightdepth = height(root->right);
    if (leftdepth > rightdepth)
        return leftdepth + 1;
    else
        return rightdepth + 1;
}
void mirrorBinaryTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
    BinaryTreeNode<int> *temp = root->left;
    root->left = root->right;
    root->right = temp;
}
void inorder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}
// Construct Tree from Preorder and Inorder
int search(int *inorder, int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == curr)
            return i;
    }
}
BinaryTreeNode<int> *convert(int *preorder, int *inorder, int start, int end)
{
    static int idx = 0;
    if (start > end)
        return NULL;
    int curr = preorder[idx];
    idx++;
    BinaryTreeNode<int> *node = new BinaryTreeNode<int>(curr);
    if (start == end)
        return node;
    int pos = search(inorder, start, end, curr);
    node->left = convert(preorder, inorder, start, pos - 1);
    node->right = convert(preorder, inorder, pos + 1, end);
}
BinaryTreeNode<int> *buildTree(int *preorder, int start, int *inorder, int end)
{
    return convert(preorder, inorder, 0, end - 1);
}
// Construct Tree from Postorder and Inorder
// int search(int *inorder, int start, int end, int curr)
// {
//     for (int i = start; i <= end; i++)
//     {
//         if (inorder[i] == curr)
//             return i;
//     }
// }
// BinaryTreeNode<int> *convert(int *postorder, int *inorder, int start, int end)
// {
//     static int idx = end;
//     if (start > end)
//         return NULL;
//     int curr = postorder[idx];
//     idx--;
//     BinaryTreeNode<int> *node = new BinaryTreeNode<int>(curr);
//     if (start == end)
//         return node;
//     int pos = search(inorder, start, end, curr);
//     node->right = convert(postorder, inorder, pos + 1, end);
//     node->left = convert(postorder, inorder, start, pos - 1);
// }
// BinaryTreeNode<int> *buildTree(int *postorder, int start, int *inorder, int end)
// {
//     return convert(postorder, inorder, 0, end - 1);
// }
// diameter of binary tree
// int height(BinaryTreeNode<int> *root)
// {
//     if (root == NULL)
//         return 0;
//     return 1 + max(height(root->left), height(root->right));
// }
int diameter(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int option1 = height(root->left) + height(root->right);
    int option2 = diameter(root->left);
    int option3 = diameter(root->right);
    return max(option1, max(option2, option3));
}
pair<int, int> heightDiameter(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    pair<int, int> leftans = heightDiameter(root->left);
    pair<int, int> rightans = heightDiameter(root->right);
    int ld = leftans.second;
    int lh = leftans.first;
    int rd = rightans.second;
    int rh = rightans.first;
    int height = 1 + max(lh, rh);
    int diameter = max(lh + rh, max(ld, rd));
    pair<int, int> p;
    p.first = height;
    p.second = diameter;
    return p;
}
void solve(BinaryTreeNode<int> *root, int &minnode, int &maxnode)
{
    if (root == NULL)
        return;
    minnode = min(minnode, root->data);
    maxnode = max(maxnode, root->data);
    solve(root->left, minnode, maxnode);
    solve(root->right, minnode, maxnode);
}
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        pair<int, int> p;
        p.first = 0;
        p.second = 0;
        return p;
    }
    int minnode = INT_MAX;
    int maxnode = INT_MIN;
    pair<int, int> p;
    solve(root, minnode, maxnode);
    p.first = minnode;
    p.second = maxnode;
    return p;
}
// sum of binary tree
int getSum(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    static int sum = 0;
    sum += root->data;
    getSum(root->left);
    getSum(root->right);
    return sum;
}
// Check Balanced
int height(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}
bool isBalanced(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return true;
    int lh = height(root->left);
    int rh = height(root->right);
    if (abs(lh - rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return true;
    return false;
}
// Level order traversal
void printLevelWise(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    queue<BinaryTreeNode<int> *> pendingnodes;
    pendingnodes.push(root);
    pendingnodes.push(NULL);
    while (pendingnodes.size())
    {
        BinaryTreeNode<int> *front = pendingnodes.front();
        pendingnodes.pop();
        if (front == NULL)
        {
            if (pendingnodes.size() == 0)
                break;
            cout << endl;
            pendingnodes.push(NULL);
        }
        else
        {
            cout << front->data << " ";
            if (front->left)
                pendingnodes.push(front->left);
            if (front->right)
                pendingnodes.push(front->right);
        }
    }
}
// Remove Leaf nodes
BinaryTreeNode<int> *removeLeafNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return NULL;
    if (root->left == NULL && root->right == NULL)
        return NULL;
    root->left = removeLeafNodes(root->left);
    root->right = removeLeafNodes(root->right);
    return root;
}
// Level wise linkedlist
// vector<Node<int> *> constructLinkedListForEachLevel(BinaryTreeNode<int> *root)
// {
//     vector<Node<int> *> v;
//     if (root == NULL)
//     {
//         v.push_back(NULL);
//         return v;
//     }
//     queue<BinaryTreeNode<int> *> pendingnodes;
//     pendingnodes.push(root);
//     pendingnodes.push(NULL);
//     Node<int> *head = NULL;
//     Node<int> *tail = head;
//     while (pendingnodes.size())
//     {
//         BinaryTreeNode<int> *front = pendingnodes.front();
//         pendingnodes.pop();
//         if (front == NULL)
//         {
//             tail->next = NULL;
//             if (pendingnodes.size() == 0)
//                 break;
//             pendingnodes.push(NULL);
//             head = NULL;
//             tail = NULL;
//         }
//         else
//         {
//             Node<int> *n = new Node<int>(front->data);
//             if (head == NULL)
//             {
//                 head = tail = n;
//                 v.push_back(head);
//             }
//             else
//             {
//                 tail->next = n;
//                 tail = n;
//             }
//             if (front->left)
//                 pendingnodes.push(front->left);
//             if (front->right)
//                 pendingnodes.push(front->right);
//         }
//     }
// }
// ZigZag tree traversal
void zigZagOrder(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    stack<BinaryTreeNode<int> *> s1;
    stack<BinaryTreeNode<int> *> s2;
    s1.push(root);
    while (!s1.empty())
    {
        while (!s1.empty())
        {
            BinaryTreeNode<int> *top = s1.top();
            s1.pop();
            cout << top->data << " ";
            if (top->left)
                s2.push(top->left);
            if (top->right)
                s2.push(top->right);
        }
        cout << endl;
        while (!s2.empty())
        {
            BinaryTreeNode<int> *top = s2.top();
            s2.pop();
            cout << top->data << " ";
            if (top->right)
                s1.push(top->right);
            if (top->left)
                s1.push(top->left);
        }
        cout << endl;
    }
}
// Nodes without sibling
void printNodesWithoutSibling(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    if (root->left && !root->right)
    {
        cout << root->left->data << " ";
        printNodesWithoutSibling(root->left);
    }
    else if (!root->left && root->right)
    {
        cout << root->right->data << " ";
        printNodesWithoutSibling(root->right);
    }
    else
    {
        printNodesWithoutSibling(root->left);
        printNodesWithoutSibling(root->right);
    }
}
// Get path from root to the path
vector<int> *getRootToNodePath(BinaryTreeNode<int> *root, int data)
{
    if (root == NULL)
        return NULL;

    if (root->data == data)
    {
        vector<int> *output = new vector<int>();
        output->push_back(root->data);
        return output;
    }

    vector<int> *leftOutput = getRootToNodePath(root->left, data);
    if (leftOutput != NULL)
    {
        leftOutput->push_back(root->data);
        return leftOutput;
    }

    vector<int> *rightOutput = getRootToNodePath(root->right, data);
    if (rightOutput != NULL)
    {
        rightOutput->push_back(root->data);
        return rightOutput;
    }
    else
        return NULL;
}
// Create & Insert Duplicate Node
void insertDuplicateNode(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    BinaryTreeNode<int> *newnode = new BinaryTreeNode<int>(root->data);
    BinaryTreeNode<int> *rootLeft = root->left;
    root->left = newnode;
    newnode->left = rootLeft;
    insertDuplicateNode(rootLeft);
    insertDuplicateNode(root->right);
}
// Pair Sum Binary Tree
void convertBTtoArr(BinaryTreeNode<int> *root, vector<int> &v)
{
    if (root == NULL)
        return;
    v.push_back(root->data);
    convertBTtoArr(root->left, v);
    convertBTtoArr(root->right, v);
}
int ArrPairSum(vector<int> v, int sum)
{
    int i = 0, j = v.size() - 1;
    while (i < j)
    {
        if (v[i] + v[j] == sum)
        {
            cout << v[i] << " " << v[j] << endl;
            i++;
            j--;
        }
        else if (v[i] + v[j] > sum)
            j--;
        else
            i++;
    }
}
void pairSum(BinaryTreeNode<int> *root, int sum)
{
    vector<int> v;
    convertBTtoArr(root, v);
    sort(v.begin(), v.end());
    ArrPairSum(v, sum);
}
//  LCA of Binary Tree
int getLCA(BinaryTreeNode<int> *root, int a, int b)
{
    if (root == NULL)
        return -1;
    if (root->data == a || root->data == b)
        return root->data;
    int left = getLCA(root->left, a, b);
    int right = getLCA(root->right, a, b);
    if (left == -1 && right == -1)
        return -1;
    else if (left != -1 && right == -1)
        return left;
    else if (left == -1 && right != -1)
        return right;
    else
        return root->data;
}
// Path Sum Root to Leaf
void solve(BinaryTreeNode<int> *root, int k, vector<int> path)
{
    if (root == NULL)
        return;
    path.push_back(root->data);
    k = k - root->data;
    // If it is a Leaf node
    if (!root->left && !root->right)
    {
        if (k == 0)
        {
            for (int i : path)
                cout << i << " ";
            cout << endl;
        }
        else
            path.pop_back();
    }
    solve(root->left, k, path);
    solve(root->right, k, path);
}
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k)
{
    vector<int> path;
    solve(root, k, path);
}
// Print nodes at distance k from node
void printkdistanceNodeDown(BinaryTreeNode<int> *root, int k)
{
    if (root == NULL || k < 0)
        return;
    if (k == 0)
        cout << root->data << endl;
    printkdistanceNodeDown(root->left, k - 1);
    printkdistanceNodeDown(root->right, k - 1);
}
int printkdistanceNode(BinaryTreeNode<int> *root, int target, int k)
{
    if (root == NULL)
        return -1;
    if (root->data == target)
    {
        printkdistanceNodeDown(root, k);
        return 0;
    }
    int dl = printkdistanceNode(root->left, target, k);
    if (dl != -1)
    {
        if (dl + 1 == k)
            cout << root->data << endl;
        else
            printkdistanceNodeDown(root->right, k - dl - 2);
        return 1 + dl;
    }
    int dr = printkdistanceNode(root->right, target, k);
    if (dr != -1)
    {
        if (dr + 1 == k)
            cout << root->data << endl;
        else
            printkdistanceNodeDown(root->left, k - dr - 2);
        return 1 + dr;
    }
    return -1;
}
void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k)
{
    int ans = printkdistanceNode(root, node, k);
}
// Check cousins
int level(BinaryTreeNode<int> *root, int node, int lev)
{
    if (root == NULL)
        return 0;
    if (root->data == node)
        return lev;
    int left = level(root->left, node, lev + 1);
    if (left != 0)
        return left;
    return level(root->right, node, lev + 1);
}
bool isSibiling(BinaryTreeNode<int> *root, int p, int q)
{
    if (root == NULL)
        return false;
    if (root->left && root->right)
    {
        if (root->left->data == p && root->right->data == q)
            return true;
        else if (root->left->data == q && root->right->data == p)
            return true;
    }
    if (root->left)
        if (isSibiling(root->left, p, q))
            return true;
    if (root->right)
        if (isSibiling(root->right, p, q))
            return true;
}
bool isCousin(BinaryTreeNode<int> *root, int p, int q)
{
    if ((level(root, p, 1) == level(root, q, 1)) && !(isSibiling(root, p, q)))
        return true;
    else
        return false;
}
// Longest Leaf to root path
int height(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}
vector<int> *longestPath(BinaryTreeNode<int> *root)
{
    if (root->left == NULL && root->right == NULL)
    {
        vector<int> *v = new vector<int>();
        v->push_back(root->data);
        return v;
    }
    int left = 0;
    int right = 0;
    if (root->left)
        left = height(root->left);
    if (root->right)
        right = height(root->right);
    if (left > right)
    {
        vector<int> *v = longestPath(root->left);
        v->push_back(root->data);
        return v;
    }
    else
    {
        vector<int> *v = longestPath(root->right);
        v->push_back(root->data);
        return v;
    }
}
// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main()
{
    BinaryTreeNode<int> *root = takeInputLevelWise();
    printLevelWise(root);
    cout << "No of nodes : " << numNodes(root) << endl;
    cout << "If node 3 is present : " << isNodePresent(root, 3) << endl;
    cout << "Height of the tree : " << height(root) << endl;
    mirrorBinaryTree(root);
    cout << "Mirror tree : " << endl;
    printLevelWise(root);
    cout << "Inorder traversal : " << endl;
    inorder(root);
    delete root;
    return 0;
}