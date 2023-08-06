#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node* right;
    Node* left;
};


 Node* createNewNode(int data)
{
      Node* node= new Node;
     node->data=data;
     node->left=node->right=NULL;

    return node;
     
}



void preOrder(Node* root)
{
      if(root==NULL)
      {
        return ;
      }
     cout<<root->data<<" ";
     preOrder(root->right);
     preOrder(root->left);
}

int height(Node* root)
{
    if(root==NULL ) return 0;

    return max(height(root->right),height(root->left))+1;
}

bool Height_balance_tree(Node* root)
{

    if(root==NULL) return true;
    
    int r=height(root->right);
    int l=height(root->left);

    if(abs(r-l)<=1 && Height_balance_tree(root->right) && height(root->left))
    {
        return true;
    }

return false;
     
}
int main()
{

     struct Node* root=NULL;
      root= createNewNode(4);
      root->right=createNewNode(5);
      root->left=createNewNode(6);
      root->right->right= createNewNode(66);
      root->left->left=createNewNode(44);
      
     



      cout<<Height_balance_tree(root);


}