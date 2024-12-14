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

// Note - Both the approaches are same

// Approach 1

// int height(BinaryTreeNode<int> *root)
// {
//     if (root == NULL)
//         return 0;
//     return 1 + max(height(root->left), height(root->right));
// }

// Approach 2

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
int search(vector<int> inorder, int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == curr)
            return i;
    }
}
BinaryTreeNode<int> *solve(vector<int> preorder,
                           vector<int> inorder, int &idx, int start, int end)
{
    if (start > end)
        return NULL;
    int currnode = preorder[idx];
    idx++;
    BinaryTreeNode<int> *node = new BinaryTreeNode(currnode);
    if (start == end)
        return node;
    int pos = search(inorder, start, end, currnode);
    node->left = solve(preorder, inorder, idx, start, pos - 1);
    node->right = solve(preorder, inorder, idx, pos + 1, end);
    return node;
}
BinaryTreeNode<int> *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int idx = 0, start = 0, end = preorder.size() - 1;
    return solve(preorder, inorder, idx, start, end);
}

// Construct Tree from Postorder and Inorder
int search(vector<int> inorder, int start, int end, int curr)
{
    for (int i = start; i <= end; i++)
    {
        if (inorder[i] == curr)
            return i;
    }
}
BinaryTreeNode<int> *solve(vector<int> inorder,
                           vector<int> postorder, int &idx, int start, int end)
{
    if (start > end)
        return NULL;
    int currnode = postorder[idx];
    idx--;
    BinaryTreeNode<int> *node = new BinaryTreeNode(currnode);
    if (start == end)
        return node;
    int pos = search(inorder, start, end, currnode);

    node->right = solve(inorder, postorder, idx, pos + 1, end);
    node->left = solve(inorder, postorder, idx, start, pos - 1);

    return node;
}
BinaryTreeNode<int> *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    int idx = inorder.size() - 1, start = 0, end = inorder.size() - 1;
    return solve(inorder, postorder, idx, start, end);
}

// diameter of binary tree
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
    return root->data + getSum(root->left) + getSum(root->right);
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
BinaryTreeNode<int> *lowestCommonAncestor(BinaryTreeNode<int> *root,
                                          BinaryTreeNode<int> *p, BinaryTreeNode<int> *q)
{
    // base case
    if (root == NULL || root == p || root == q)
        return root;

    BinaryTreeNode<int> *left = lowestCommonAncestor(root->left, p, q);
    BinaryTreeNode<int> *right = lowestCommonAncestor(root->right, p, q);

    // results
    if (left == NULL)
        return right;
    else if (right == NULL)
        return left;
    else
        return root; // we found the result as both are not NULL
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

// All Nodes Distance K in Binary Tree
void markParents(BinaryTreeNode<int> *root, unordered_map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> &parent)
{
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            BinaryTreeNode<int> *node = q.front();
            q.pop();
            if (node->left)
            {
                parent[node->left] = node;
                q.push(node->left);
            }
            if (node->right)
            {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }
}
void solve(BinaryTreeNode<int> *target, unordered_map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> &parent, unordered_map<BinaryTreeNode<int> *, bool> &visited, int k, vector<int> &ans)
{
    if (k == 0)
        ans.push_back(target->data);

    visited[target] = true;
    if (target->left && !visited[target->left])
        solve(target->left, parent, visited, k - 1, ans);

    if (target->right && !visited[target->right])
        solve(target->right, parent, visited, k - 1, ans);

    if (parent[target] != NULL && !visited[parent[target]])
        solve(parent[target], parent, visited, k - 1, ans);
}
vector<int> distanceK(BinaryTreeNode<int> *root, BinaryTreeNode<int> *target, int k)
{
    unordered_map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> parent; // node -> parent
    markParents(root, parent);

    unordered_map<BinaryTreeNode<int> *, bool> visited;
    vector<int> ans;
    solve(target, parent, visited, k, ans);
    return ans;
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

// Binary Tree Maximum Path Sum
int maxPathDown(BinaryTreeNode<int> *root, int &maxi)
{
    if (root == NULL)
        return 0;
    int left = max(0, maxPathDown(root->left, maxi));
    int right = max(0, maxPathDown(root->right, maxi));
    maxi = max(maxi, left + right + root->data);
    return root->data + max(left, right);
}
int maxPathSum(BinaryTreeNode<int> *root)
{
    int maxi = INT_MIN;
    maxPathDown(root, maxi);
    return maxi;
}

// Same Tree
// bool isSameTree(TreeNode *p, TreeNode *q)
// {
//     if (p == NULL && q == NULL)
//         return true;
//     if (p == NULL || q == NULL)
//         return false;
//     return (p->val == q->val) && isSameTree(p->left, q->left) &&
//            isSameTree(p->right, q->right);
// }

// Boundary Traversal of Binary Tree
void addLeftBoundary(BinaryTreeNode<int> *root, vector<int> &ans)
{
    BinaryTreeNode<int> *curr = root->left;
    while (curr)
    {
        if (curr->left || curr->right)
            ans.push_back(curr->data);
        if (curr->left)
            curr = curr->left;
        else
            curr = curr->right;
    }
}
void addLeaves(BinaryTreeNode<int> *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }
    addLeaves(root->left, ans);
    addLeaves(root->right, ans);
}

void addRightBoundary(BinaryTreeNode<int> *root, vector<int> &ans)
{
    BinaryTreeNode<int> *curr = root->right;
    vector<int> tmp;
    while (curr)
    {
        if (curr->left || curr->right)
            tmp.push_back(curr->data);
        if (curr->right)
            curr = curr->right;
        else
            curr = curr->left;
    }

    for (int i = tmp.size() - 1; i >= 0; --i)
        ans.push_back(tmp[i]);
}
vector<int> traverseBoundary(BinaryTreeNode<int> *root)
{
    vector<int> ans;

    // edge cases
    if (root == NULL)
        return ans;
    if (root->left == NULL && root->right == NULL)
        return {root->data};

    ans.push_back(root->data);

    addLeftBoundary(root, ans);  // Add left boundary (excluding the root)
    addLeaves(root, ans);        // Add all leaf nodes
    addRightBoundary(root, ans); // Add right boundary (excluding the root and leaves)

    return ans;
}

// Vertical Order Traversal
vector<vector<int>> findVertical(BinaryTreeNode<int> *root)
{
    // Map to store nodes based on vertical and level information
    map<int, map<int, multiset<int>>> nodes;

    // Queue for BFS traversal, each
    // element is a pair containing node
    // and its vertical and level information
    queue<pair<BinaryTreeNode<int> *, pair<int, int>>> todo;

    todo.push({root, {0, 0}});

    while (!todo.empty())
    {
        auto p = todo.front();
        todo.pop();
        BinaryTreeNode<int> *temp = p.first;

        int x = p.second.first;
        int y = p.second.second;

        nodes[x][y].insert(temp->data);

        if (temp->left)
            todo.push({temp->left, {x - 1, y + 1}});

        if (temp->right)
            todo.push({temp->right, {x + 1, y + 1}});
    }
    vector<vector<int>> ans;
    for (auto p : nodes)
    {
        vector<int> col;
        for (auto q : p.second)
            col.insert(col.end(), q.second.begin(), q.second.end());
        ans.push_back(col);
    }
    return ans;
}

// Top view
vector<int> topView(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    map<int, int> mpp;                         // line no and node value
    queue<pair<BinaryTreeNode<int> *, int>> q; // node and line no
    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        auto node = it.first;
        int line = it.second;
        if (mpp.find(line) == mpp.end())
            mpp[line] = node->data;
        if (node->left)
            q.push({node->left, line - 1});
        if (node->right)
            q.push({node->right, line + 1});
    }
    for (auto it : mpp)
        ans.push_back(it.second);
    return ans;
}

// Bottom View
vector<int> bottomView(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    map<int, int> mpp;                         // line no and node value
    queue<pair<BinaryTreeNode<int> *, int>> q; // node and line no
    q.push({root, 0});

    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        auto node = it.first;
        int line = it.second;
        mpp[line] = node->data;
        if (node->left)
            q.push({node->left, line - 1});
        if (node->right)
            q.push({node->right, line + 1});
    }
    for (auto it : mpp)
        ans.push_back(it.second);
    return ans;
}

// Right side view
void solveright(BinaryTreeNode<int> *root, int level, vector<int> &ans)
{
    if (root == NULL)
        return;
    if (level == ans.size())
        ans.push_back(root->data);
    solveright(root->right, level + 1, ans);
    solveright(root->left, level + 1, ans);
}
vector<int> rightSideView(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    solveright(root, 0, ans);
    return ans;
}

// Left side view
void solveleft(BinaryTreeNode<int> *root, int level, vector<int> &ans)
{
    if (root == NULL)
        return;
    if (level == ans.size())
        ans.push_back(root->data);
    solveleft(root->left, level + 1, ans);
    solveleft(root->right, level + 1, ans);
}
vector<int> leftSideView(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    solveleft(root, 0, ans);
    return ans;
}

// Symmetric Tree
bool checkSymmetric(BinaryTreeNode<int> *left, BinaryTreeNode<int> *right)
{
    if (left == NULL || right == NULL)
        return left == right;
    if (left->data != right->data)
        return false;
    return checkSymmetric(left->left, right->right) &&
           checkSymmetric(left->right, right->left);
}
bool isSymmetric(BinaryTreeNode<int> *root)
{
    return root == NULL || checkSymmetric(root->left, root->right);
}

// Root to Leaf Paths
void findpaths(BinaryTreeNode<int> *root, vector<int> &currpath, vector<vector<int>> &allpaths)
{
    if (root == NULL)
        return;

    currpath.push_back(root->data);

    if (root->left == NULL && root->right == NULL)
        allpaths.push_back(currpath);
    else
    {
        findpaths(root->left, currpath, allpaths);
        findpaths(root->right, currpath, allpaths);
    }

    currpath.pop_back();
}
vector<vector<int>> Paths(BinaryTreeNode<int> *root)
{
    vector<vector<int>> allpaths;
    vector<int> currpath;
    findpaths(root, currpath, allpaths);
    return allpaths;
}

// Maximum Width of Binary Tree
int widthOfBinaryTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    int ans = 0;

    queue<pair<BinaryTreeNode<int> *, int>> q;
    q.push({root, 0});

    while (!q.empty())
    {
        int size = q.size();
        int mmin = q.front().second;
        int first, last;

        for (int i = 0; i < size; i++)
        {
            int cur_id = q.front().second - mmin;
            BinaryTreeNode<int> *node = q.front().first;
            q.pop();
            if (i == 0)
                first = cur_id;
            if (i == size - 1)
                last = cur_id;
            if (node->left)
                q.push({node->left, (long long)cur_id * 2 + 1});
            if (node->right)
                q.push({node->right, (long long)cur_id * 2 + 2});
        }
        ans = max(ans, last - first + 1);
    }
    return ans;
}

// Children Sum in a Binary Tree
int isSumProperty(BinaryTreeNode<int> *root)
{
    // base case
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return 1;

    int leftData = (root->left != NULL) ? root->left->data : 0;
    int rightData = (root->right != NULL) ? root->right->data : 0;

    return root->data == leftData + rightData &&
           isSumProperty(root->left) &&
           isSumProperty(root->right);
}

// Minimum time taken to BURN the Binary Tree from a Node
BinaryTreeNode<int> *markParents(BinaryTreeNode<int> *root, unordered_map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> &parent, int target)
{
    BinaryTreeNode<int> *targetnode;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            auto *node = q.front();
            q.pop();
            if (node->data == target)
                targetnode = node;
            if (node->left)
            {
                parent[node->left] = node;
                q.push(node->left);
            }
            if (node->right)
            {
                parent[node->right] = node;
                q.push(node->right);
            }
        }
    }
    return targetnode;
}
int findminimum(unordered_map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> parent, BinaryTreeNode<int> *targetnode)
{
    queue<BinaryTreeNode<int> *> q;
    q.push(targetnode);
    unordered_map<BinaryTreeNode<int> *, bool> visited;
    visited[targetnode] = true;
    int mini = 0;

    while (!q.empty())
    {
        int sz = q.size();
        int fl = 0;
        for (int i = 0; i < sz; i++)
        {
            auto node = q.front();
            q.pop();
            if (node->left && !visited[node->left])
            {
                fl = 1;
                visited[node->left] = true;
                q.push(node->left);
            }
            if (node->right && !visited[node->right])
            {
                fl = 1;
                visited[node->right] = true;
                q.push(node->right);
            }
            if (parent[node] && !visited[parent[node]])
            {
                fl = 1;
                visited[parent[node]] = true;
                q.push(parent[node]);
            }
        }
        if (fl)
            mini++;
    }
    return mini;
}
int minTime(BinaryTreeNode<int> *root, int target)
{
    unordered_map<BinaryTreeNode<int> *, BinaryTreeNode<int> *> parent; // node -> parent
    BinaryTreeNode<int> *targetnode = markParents(root, parent, target);
    int mini = findminimum(parent, targetnode);
    return mini;
}

// Count Complete Tree Nodes
int findheightleft(BinaryTreeNode<int> *root)
{
    int leftht = 0;
    while (root)
    {
        leftht++;
        root = root->left;
    }
    return leftht;
}
int findheightright(BinaryTreeNode<int> *root)
{
    int rightht = 0;
    while (root)
    {
        rightht++;
        root = root->right;
    }
    return rightht;
}
int countNodes(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;

    int lh = findheightleft(root);
    int rh = findheightright(root);

    if (lh == rh)
        return (1 << lh) - 1;

    return 1 + countNodes(root->left) + countNodes(root->right);
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