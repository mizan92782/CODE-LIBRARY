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

Node* createTernarytree(int data)
{

       Node* x= new Node;
       x->data=data;
       x->left=x->right=x->middle=NULL;


     return x; 
  
}


void  MakeTree(Node* root,int data)
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












void levelOrder_stl(Node *root)
{
    if (root == NULL) return;
 
    // Create an empty queue for
    // level order traversal
    queue<Node *> q;
     
    // to store front element of
    // queue.
    Node *curr;
 
    // Enqueue Root and NULL node.
    q.push(root);
    q.push(NULL);
 
    while (q.size() > 1)
    {
        curr = q.front();
        q.pop();
         
        // condition to check
        // occurrence of next
        // level.
        if (curr == NULL)
        {
           q.push(NULL);
           cout << "\n";
        }
         
        else {
             
            // pushing left child of
            // current node.
            if(curr->left)
            q.push(curr->left);

              if(curr->middle)
            q.push(curr->middle);
             
            // pushing right child of
            // current node.
            if(curr->right)
            q.push(curr->right);


             
            cout << curr->data << " ";
        }
    }
}





int main()
{
      Node* root=NULL;
      root=createTernarytree(1);
     
  
      MakeTree(root,3);
      MakeTree(root,4);
      MakeTree(root,5);
      MakeTree(root,6);
      MakeTree(root,23);
      MakeTree(root,65);
      MakeTree(root,12);
      MakeTree(root,33);
      MakeTree(root,6);



      levelOrder_stl(root);



}