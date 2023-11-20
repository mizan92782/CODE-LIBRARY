#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};


Node* newNode(int data)
{
     Node* node = new Node;
     node->data=data;
     node->right=node->right=NULL;
    return node;
}



 int sumOfTree(Node* root)
 {
     if(root==NULL) return 0;
   
   return root->data +sumOfTree(root->left) + sumOfTree(root->right);
 }



 bool subtree_sum(Node* root,int sum)
 {
      if(root->left==NULL && root->left==NULL) return false ;
     int x= sumOfTree(root->right);
     int y=sumOfTree(root->left);

     

     return (x==sum) || (y==sum) || subtree_sum(root->right,sum) || subtree_sum(root->left,sum);
 }

int main()
{
      //* https://www.geeksforgeeks.org/write-c-code-to-determine-if-two-trees-are-identical/


    // * First tree
    Node *root =NULL;
     root= newNode(8);
    root->left    = newNode(5);
    root->right   = newNode(4);
    root->left->left = newNode(9);
    root->left->right = newNode(7);
    root->left->right->left = newNode(1);
    root->left->right->right = newNode(12);
    root->left->right->right->right = newNode(2);
    root->right->right = newNode(11);
    root->right->right->left = newNode(3);
    int sum = 22;
 
    if (subtree_sum(root, sum))
        cout << "Yes";
    else
        cout << "No";



        return 0;
     
}