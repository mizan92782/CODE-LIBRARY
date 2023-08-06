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



int Level(Node* root,int a,int lev)
{
     if(root==NULL) return 0;
     if(root->data==a) return lev;
     
     // Return level if Node is present in left subtree
     int  l= Level(root->left,a,lev+1);
     if(l!=0)
     {
        return l;
     }


    // Else search in right subtree
    return Level(root->right,a,lev+1);

}




// Recursive function to check if two Nodes are siblings
bool isSibling(struct Node* root, int  a,
              int  b)
{
    // Base case
    if (root == NULL)
        return false;
        
        
   if(root->left==NULL || root->right==NULL)
   {
       return false;
   }
 
    return ((root->left->data == a && root->right->data == b)
            || (root->left->data == b && root->right->data == a)
            || isSibling(root->left, a, b)
            || isSibling(root->right, a, b));
}

bool isCousins(Node *root, int a, int b)
{
   if((Level(root,a,1)== Level(root,b,1)) && !(isSibling(root, a, b)))
     {
            return true;
     }

     return false;
}



int main()
{

     struct Node* root=NULL;
     root=createNewNode(1);
    root->left = createNewNode(2);
    root->right = createNewNode(3);
    root->left->left = createNewNode(4);
    root->left->right = createNewNode(5);
    root->left->right->right = createNewNode(15);
    root->right->left = createNewNode(6);
    root->right->right = createNewNode(7);
    root->right->left->right = createNewNode(8);




    if (isCousins(root, 4,5))
        printf("Yes\n");
    else
        printf("No\n");

     


}