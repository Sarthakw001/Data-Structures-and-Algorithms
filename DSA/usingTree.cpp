#include <iostream>
#include <iostream>
#include <vector>
#include <string>
#include "tree.h"
#include <queue>
using namespace std;

treeNode<int> *takeInputLevelTraversal()
{
    int rootData;
    cout << "Enter the root Data :" << endl;
    cin >> rootData;
    treeNode<int> *root = new treeNode<int>(rootData);
    queue<treeNode<int> *> pendingNodes;
    pendingNodes.push(root);
    while (pendingNodes.size() != 0)
    {
        treeNode<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int n;
        cout << "No. of nodes for " << front->data << endl;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int childNodeData;
            cout << "enter the node data for " << front->data << endl;
            cin >> childNodeData;
            treeNode<int> *children = new treeNode<int>(childNodeData);
            front->children.push_back(children);
            pendingNodes.push(children);
        }
    }
    return root;
}
treeNode<int> *takeInput()
{
    int rootData;
    cout << "enter data : " << endl;
    cin >> rootData;
    treeNode<int> *root = new treeNode<int>(rootData);

    cout << "Enter No. of children of :" << rootData << endl;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        treeNode<int> *childern = takeInput();
        root->children.push_back(childern);
    }
    return root;
}
void printTreeLevelTraversal(treeNode<int> *root)
{
    queue<treeNode<int> *> pendingNode;
    pendingNode.push(root);
    cout<<root->data<<endl;
    while (pendingNode.size() != 0)
    {
        treeNode<int> *front = pendingNode.front();
        pendingNode.pop();
        for (int i = 0; i < front->children.size(); i++)
        {
            cout << front->children[i]->data << ",";
        }
        cout << endl;
        for (int i = 0; i < front->children.size(); i++)
        {
            pendingNode.push(front->children[i]);
        }
    }
}
void printTree(treeNode<int> *root)
{
    cout << root->data << ":";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children[i]->data << ",";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        printTree(root->children[i]);
    }
}
int countNodes(treeNode<int> *root)
{
    int ans = 1;
    for (int i = 0; i < root->children.size(); i++)
    {
        ans = ans + countNodes(root->children[i]);
    }
    return ans;
}
int sumOfNodes(treeNode<int> *root)
{
    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        sum = sum + sumOfNodes(root->children[i]);
    }
    return sum;
}
int maxTreeNode(treeNode<int> *root)
{
    int max = root->data;
    for (int i = 0; i < root->children.size(); i++)
    {
        int max1 = maxTreeNode(root->children[i]);
        if (max1 > max)
        {
            max = max1;
        }
    }
    return max;
}
int height(treeNode<int> *root)
{
    int h1 = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        int h = height(root->children[i]);
        h1 = max(h, h1);
    }
    return h1 + 1;
}

void printTreeNodeAtLevelK(treeNode<int> *root, int k)
{
    if (root == NULL)
    {
        return;
    }
    if (k == 0)
    {
        cout << root->data << " ";
        return;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        printTreeNodeAtLevelK(root->children[i], k - 1);
    }
}
int countLeafNode(treeNode<int> *root)
{
    if (root->children.size() == 0)
    {
        return 1;
    }
    int n = 0;
    for (int i = 0; i < root->children.size(); i++)
    {
        n = n + countLeafNode(root->children[i]);
    }
    return n;
}

void postOrderTraversal(treeNode<int> *root)
{
    for (int i = 0; i < root->children.size(); i++)
    {
        postOrderTraversal(root->children[i]);
    }
    cout << root->data << " ";
}
bool checkX(treeNode<int> *root, int x)
{

    if (root->data == x)
    {
        return true;
    }
    else
    {
        for (int i = 0; i < root->children.size(); i++)
        {
            bool s = checkX(root->children[i], x);
            if (s)
            {
                return true;
            }
        }
    }
    return false;
}
int frequencyX(treeNode<int> *root, int x)
{
    queue<treeNode<int> *> pn;
    pn.push(root);
    int n = 0;
    while (pn.size() != 0)
    {
        treeNode<int> *front = pn.front();
        pn.pop();
        if (front->data > x)
        {
            n++;
        }
        for (int i = 0; i < front->children.size(); i++)
        {
            pn.push(front->children[i]);
        }
    }
    return n;
}
int maxTreeNodes(treeNode<int> *root)
{
    static int ans = root->data;
    static int sum = 0;
    for (static int i = 0; i < root->children.size(); i++)
    {
        sum = root->data + root->children[i]->data;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        int n = maxTreeNodes(root->children[i]);
        int sum1 = root->data + root->children[i]->data;
        if (sum1 > sum)
        {
            ans = root->data;
            sum = sum1;
        }
    }
    return ans;
}

bool structuallyIdentical(treeNode<int> *root1, treeNode<int> *root2)
{
    queue<treeNode<int> *> pd1;
    queue<treeNode<int> *> pd2;

    pd1.push(root1);
    pd2.push(root2);
    vector<bool> v;
    while (pd1.size() != 0 && pd2.size() != 0)
    {
        treeNode<int> *f1 = pd1.front();
        treeNode<int> *f2 = pd2.front();
        pd1.pop();
        pd2.pop();
        if (f1->data == f2->data)
        {
            v.push_back(true);
        }
        else
        {
            v.push_back(false);
        }
        for (int i = 0; i < f1->children.size(); i++)
        {
            pd1.push(f1->children[i]);
        }
        for (int i = 0; i < f2->children.size(); i++)
        {
            pd2.push(f2->children[i]);
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == false)
        {
            return false;
        }
    }
    return true;
}

int nextLarger(treeNode<int> *root, int n)
{
    int ans;
    if (root->data > n)
    {
        ans = root->data;
    }
    for (int i = 0; i < root->children.size(); i++)
    {
        int temp = nextLarger(root->children[i], n);
        ans = min(temp, ans);
    }
    return ans;
}

// int secondLargest(treeNode<int> *root)
// {
//     static int max1 = maxTreeNode(root);
//     int ans;
//     int smax = root->data;
//     for (int i = 0; i < root->children.size(); i++)
//     {
//         int smax1 = secondLargest(root->children[i]);
//         smax = max(smax1,smax);
//         ans = min(smax,max1);
//     }
//     return ans;
// }

void replaceWithDepth(treeNode<int> *root)
{
    queue<treeNode<int> *> pd;
    pd.push(root);
    int s = 0;
    root->data = s;
    s++;
    while (pd.size() != 0)
    {
        treeNode<int> *front = pd.front();
        pd.pop();
        for (int i = 0; i < front->children.size(); i++)
        {
            front->children[i]->data = s;
        }
        s++;
        for (int i = 0; i < front->children.size(); i++)
        {
            pd.push(front->children[i]);
        }
    }
}

void helper(treeNode<int>* root,int depth)
{
    for(int i=0;i<root->children.size();i++)
    {
        root->children[i]->data = depth;
        helper(root->children[i],depth+1);
    }
}

void replaceWithDepthR(treeNode<int> *root)
{
    int depth = 0;
    root->data = depth;
    helper(root,depth+1);
}

int main()
{
    treeNode<int> *root1 = takeInputLevelTraversal();
    replaceWithDepthR(root1);
    printTreeLevelTraversal(root1);
}
// 5 3 1 2 3 1 15 2 4 5 1 6 0 0 0 0
