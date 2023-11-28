#include<bits/stdc++.h>
using namespace std;

struct Node
{
    /* data */
    int data;
    Node* right;
    Node* left;
    Node* next;
};


Node* newnode(int data)
{
     Node* node = new Node;
     node->data=data;
     node->right=node->left=node->next=NULL;
     return node;
}








void populated_inorder_successor(Node* root)
{

     /*
      ! static assing value once along programm run time
      ! and store data for multipole time recursive call
      ! its assing only once and store value for every recursive call

     */


     static   Node* Next =NULL;

     if(root)
     {
         // * as inorder traverse right node positons in after
         populated_inorder_successor(root->right);

         root->next=Next;
         Next=root;

         populated_inorder_successor(root->left);

     }
}



void print_inordersuccesr(Node* root)
{
     queue<Node*>que;
     que.push(root);

     while (!que.empty())
     {
         Node* x =que.front();
         que.pop();

         if(x->next==NULL) 
         {
            cout<<x->data<<" inorder successor  : "<<-1;
         }else{
             cout<<x->data<<" inorder successor  : "<<x->next->data;
         }
         cout<<endl;
        if(x->right) que.push(x->right);
        if(x->left) que.push(x->left);
     }
     
}


int main()
{

    Node* root = newnode(10);
    root->left = newnode(8);
    root->right = newnode(12);
    root->left->left = newnode(3);

    populated_inorder_successor(root);
    print_inordersuccesr(root);
      

}