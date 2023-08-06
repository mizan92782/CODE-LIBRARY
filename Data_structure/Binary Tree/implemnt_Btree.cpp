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

int main()
{

     struct Node* root=NULL;
      root= createNewNode(4);
      root->right=createNewNode(5);
      root->left=createNewNode(6);
      root->right->right= createNewNode(66);
      root->left->left=createNewNode(44);
      
      insertion(root,1);
      insertion(root,11);
      insertion(root,111);
      insertion(root,1111);
      insertion(root,11111);



      preOrder(root);


}