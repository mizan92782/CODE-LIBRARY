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



void insertion(Node* root,int data)
{
    if(root==NULL) 
    {
        root=createNewNode(data);
        return ;
    }

    queue<Node*>que;
    que.push(root);

    bool set=true;

    while (set)
    {
       Node* x=que.front();
       que.pop();

       if(x->right==NULL)
       {
        x->right=createNewNode(data);
        set=false;
       }else if(x->left==NULL)
       {
        x->left=createNewNode(data);
        set=false;
       }else{
        que.push(x->right);
        que.push(x->left);
       }
    }
    
}


bool checking_full_binaryTree(Node* root)
{
    //https://www.programiz.com/dsa/full-binary-tree
    //https://www.geeksforgeeks.org/skewed-binary-tree/
    if(root==NULL)
    {
        return true;
    }


      // Checking for the presence of children
    if(root->right==NULL && root->left==NULL)
    {
        return true;
    }


    if(root->right && root->left)
    {
        return checking_full_binaryTree(root->right) && checking_full_binaryTree(root->left);
    }

    return false;
}






int main()
{

     struct Node* root=NULL;
      root= createNewNode(1);
      root->right=createNewNode(2);
      root->left=createNewNode(3);
      root->right->right= createNewNode(4);
      root->left->left=createNewNode(5);
      
      insertion(root,6);
      insertion(root,7);
      insertion(root,8);
      insertion(root,9);
      insertion(root,10);
      insertion(root,11);



      preOrder(root);

       cout<<endl;
      if(checking_full_binaryTree(root))
      {
        cout<<"its a full Binary tree\n";
      }else{
         cout<<"its not a full binary tree\n";
      }


}