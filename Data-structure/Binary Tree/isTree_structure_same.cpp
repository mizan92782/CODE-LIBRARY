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






bool isTreeSame(Node* one,Node* two)
{
      
      // ** if both tree is noll ot any childs is leaf of two three
      if(one==NULL && two==NULL)
      {
        return true;
      }


       // ** if one has leaf nut another has not
      if(one==NULL || two==NULL)
      {
        return false;
      }




      return isTreeSame(one->right,two->right) &&  isTreeSame(one->left,two->left) ;
}



int main()
{

    // ! its like to cheking same tree,only difference is we dont consider value,consider only structure
 
    // * First tree
    Node* root=NULL;
    root=newNode(1);

    root->right= newNode(2);
    root->left= newNode(3);

    root->right->right= newNode(4);
    root->right->left= newNode(5);

    root->left->right= newNode(6);
    root->left->left= newNode(7);







    // * second tree
    Node* root1=NULL;
    root1=newNode(1);

    root1->right= newNode(2);
    root1->left= newNode(3);

    root1->right->right= newNode(4);
    root1->right->left= newNode(5);

    root1->left->right= newNode(6);
    root1->left->left= newNode(7);



    // * Cheking Tree are same
    if(isTreeSame(root,root1))
    {
        cout<<"Tree are same "<<endl;
    }else{
         cout<<"Tree are not same"<<endl;
    }



     // * Changing one value
       root1->left->right->left= newNode(10);

       

     if(isTreeSame(root,root1))
    {
        cout<<"Tree are same "<<endl;
    }else{
         cout<<"Tree are not same"<<endl;
    }
     
}