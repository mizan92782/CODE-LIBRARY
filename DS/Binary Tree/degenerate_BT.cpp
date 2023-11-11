#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *right;
    Node *left;
};

Node *createNode(int data)
{
    Node *node = new Node;

    node->data = data;
    node->right = node->left = NULL;

    return node;
}

Node *insertion(Node *root, int data)
{
    // right skewed degenated tree

    if (root == NULL)
    {
        root = createNode(data);
    }
    else
    {
        root->right = insertion(root->right, data);
    }

    return root;
}

void print_tree(Node *root)
{
    if (root != NULL)
    {
        cout << root->data << " ";
        print_tree(root->right);
    }
}

int main()
{

    // https://www.geeksforgeeks.org/introduction-to-degenerate-binary-tree/

    Node *root = NULL;

    root = insertion(root, 1);

    insertion(root, 2);
    insertion(root, 3);
    insertion(root, 4);
    insertion(root, 5);
    insertion(root, 6);

    print_tree(root);

    return 0;
}