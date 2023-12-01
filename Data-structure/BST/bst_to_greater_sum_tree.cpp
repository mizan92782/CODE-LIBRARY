#include<iostream>
using namespace std;
 
// A BST node
struct Node
{
    int data;
    struct Node *left, *right;
};
 
// A utility function to create a new Binary Tree Node
struct Node *newNode(int item)
{
    struct Node *temp =  new Node;
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}
 
// Recursive function to transform a BST to sum tree.
// This function traverses the tree in reverse inorder so
// that we have visited all greater key nodes of the currently
// visited node

void printInorder(struct Node *root)
{
    if (root == NULL) return;
 
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}
 


// ******** make greaer sum tree

void makeGreatesumtree(Node* root,int& sum)
{
    if(root==NULL) return ;
    makeGreatesumtree(root->right,sum);
   
    sum=sum+root->data;
    root->data=sum-root->data;



     makeGreatesumtree(root->left,sum);
}

// Driver Program to test above functions
int main()
{


     //! leetcode and gfg  greater sum approch have differnt
      //** must be code both
      //https://www.geeksforgeeks.org/transform-bst-sum-tree/
      //https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/description/



      
    struct Node *root = newNode(11);
    root->left = newNode(2);
    root->right = newNode(29);
    root->left->left = newNode(1);
    root->left->right = newNode(7);
    root->right->left = newNode(15);
    root->right->right = newNode(40);
    root->right->right->left = newNode(35);
 
    cout << "Inorder Traversal of given tree\n";
    printInorder(root);
 
 
     int sum=0;
     makeGreatesumtree(root,sum);
    cout << "\n\nInorder Traversal of transformed tree\n";
    printInorder(root);
 
    return 0;
}