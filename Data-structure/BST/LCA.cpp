#include<bits/stdc++.h>
using namespace std;


//node;
struct Node{

   int data;
   Node* left;
   Node*  right;
};




// ! create new Node;
Node* createNewNode(int data)
{
      Node* node = new Node;
      node->data=data;
      node->left=NULL;
      node->right=NULL;

    return node;
};





//! insetion in tree;
Node* insertion(Node* root,int data)
{
     // case 1: this is null;
     if(root==NULL)
     { 

         return createNewNode(data);
     }


     if(root->data<data)
     {
          root->right=insertion(root->right,data);
     }else if (root->data> data)
     {
         root->left=insertion(root->left,data);
     }


     return root;
}








int Height(Node* root)
{
     if(root==NULL ) return 0;

    return max(Height(root->right),Height(root->left))+1;
}



void printGivenLevel(struct Node* root,
                     int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout <<" "<< root->data;
    else if (level > 1) {
  
        // Recursive Call
        printGivenLevel(root->left, level - 1);
        printGivenLevel(root->right, level - 1);
    }
}
  

void printLevelwise(Node* root)
{
     int h=Height(root);
     for(int i=1;i<=h;i++)
     {
         printGivenLevel(root,i);
         cout<<endl;
     }
}






// ! *************** Lowest common ancestor ***********88

Node* Lca(Node* root,int n1,int n2)
{

    // base case 
    if(root==NULL) return NULL ;


    // * if n1,n1 less thar curent node ,that means we check now left node
    if(root->data > n1 && root->data > n2)
    {
        return Lca(root->left,n1,n2);
    }


        // * if n1,n1 greater thar curent node ,that means we check now left node

    if(root->data < n1 && root->data < n2)
    {
        return Lca(root->right,n1,n2);
    }

      
      //! ***other wise one in left anoth in  right, so this node is lca

    return root;
}





int main()
{


    //https://www.geeksforgeeks.org/lowest-common-ancestor-in-a-binary-search-tree/
      Node* root=NULL;
      
      root= insertion(root,20);
      root= insertion(root,8);
      root= insertion(root,22);
      root= insertion(root,4);
      root= insertion(root,12);
      root= insertion(root,10);
      root= insertion(root,14);


      printLevelwise(root);


      cout<<"lca of 14 and 10  :  " <<Lca(root,10,14)->data;



}