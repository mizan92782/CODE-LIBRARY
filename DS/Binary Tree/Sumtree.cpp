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



//**** how to find sum of tree;
//**  top to bottom sum approach and not change node value

int sum(Node* root)
{
    if(root==NULL)
    {
        return 0;
    }

    return root->data+sum(root->left)+sum(root->right);
}





//*** revere order sum ,bottom to top
// ! very very important
int sum_tee_vvi(Node* root)
{
    if(root==NULL) return 0;
    if(root->left==NULL && root->right==NULL) 
    {
       
        return root->data;
    }
    int l=sum_tee_vvi(root->left);
    int r=sum_tee_vvi(root->right);
    
    return l+r+root->data;
}








bool isSumtree(Node* root)
{
     if(root==NULL || (root->right==NULL && root->left==NULL))
     {
        return true;
     }


     int l=sum(root->right);
     int r=sum(root->left);

     if((l+r==root->data) &&  isSumtree(root->right) && isSumtree(root->left))
     {
        return true;
     }


     return false;

}


int main()
{

    //https://www.geeksforgeeks.org/check-if-a-given-binary-tree-is-sumtree/
     struct Node* root=NULL;
      root= createNewNode(26);
      root->left= createNewNode(10);
      root->right=createNewNode(3);
      root->left->left=createNewNode(4);
      root->left->right= createNewNode(6);
      root->right->right=createNewNode(3);
      
      
       cout<<sum(root)<<" "<<sum_tee_vvi(root)<<endl
     

      cout<<isSumtree(root);



}