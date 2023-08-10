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


//* cheking mirror,know left and child act like two tree

bool Mirror(Node* one ,Node* two)
{      

        if(one==NULL && two==NULL) return true;
        if((one==NULL && two!=NULL) || (two==NULL && one!=NULL ) )return   false;
      
    

       return   (one->data==two->data) &&  Mirror( one->left ,two->right)   &&  Mirror(one->right ,two->left)  ; 
}




    
    
//* return true/false denoting whether the tree is Symmetric or not
bool isSymmetric( Node* root)
    {
        // * if tree is null
	    if(root==NULL) return true;

      //* if root havet no chield
      if(root->right==NULL && root->left==NULL) return true;

      //* checking mirror for right and left child,if ther are mirror ,that means the tree is Symmetric tree
      return Mirror(root->right,root->left);
        // Code here
    }

int main()
{
    // https://www.geeksforgeeks.org/symmetric-tree-tree-which-is-mirror-image-of-itself/

    
    // * First tree
     Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(2);
    root->left->left = newNode(3);
    root->left->right = newNode(4);
    root->right->left = newNode(4);
    root->right->right = newNode(3);



    if(isSymmetric(root))
    {
        cout<<"Symmetric";
    }else{
         cout<<"not symmetric"<<endl;
    }







}