
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
void PreorderTraverse(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << endl;
    PreorderTraverse(root->left);
    PreorderTraverse(root->right);
}
void InorderTraverse(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    InorderTraverse(root->left);
    cout << root->data << endl;
    InorderTraverse(root->right);
}
void PostorderTraverse(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    PostorderTraverse(root->left);
    InorderTraverse(root->right);
    cout << root->data << endl;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(5);
    cout << "PreorderTraverse"
         << endl;

    PreorderTraverse(root);
    cout << "PreorderTraverse"
         << endl;
    PreorderTraverse(root);
    cout << "PostOrder"
         << endl;
    PostorderTraverse(root);

    return 0;
}