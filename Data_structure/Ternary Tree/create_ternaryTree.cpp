#include<bits/stdc++.h>
using namespace std;


struct  Node
{
    /* data */
    int  data;
    Node* left;
    Node* middle;
    Node* right;
};



Node* newNode(int data)
{
     Node* node= new Node;
     node->data=data;
     node->left=node->middle=node->right=NULL;
     return node;
}


Node*h MakeTree(Node* root,int data)
{
    



     if(root==NULL) 
     {
        root= newNode(data); 
        return ;
     }



     queue<Node*>que;

    

     que.push(root);
    

     while (1)
     {
         Node* x= que.front();
         que.pop();

         if(x->left==NULL)
         {
             x->left= newNode(data); ;
             break;

         }else{
             que.push(x->left);
         }


          if(x->middle==NULL)
         {
             x->middle= newNode(data); ;
             break;

         }else{
             que.push(x->middle);
         }

          if(x->right==NULL)
         {
             x->right= newNode(data); 
             break;

         }else{
             que.push(x->right);
         }
     }
     
}



int main()
{
      Node* root=NULL;
     
      root=MakeTree(root,1);
     root=MakeTree(root,2);
      MakeTree(root,3);
      MakeTree(root,4);
      MakeTree(root,5);
      MakeTree(root,6);



      cout<<root->middle<<endl;
}