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







//  ! *   ********** inorder successor : *********;



void inorderTraverse(Node* root)
{    
    if(root==nullptr) return;
    inorderTraverse(root->left);
    cout<<root->data<<" ";
    inorderTraverse(root->right);
}





//* Search is this node exits
Node* Search(Node* root,int key)
{
     /*
       if return null : Node not exist
       if return not null : node exist;
    */
     if(root==NULL || root->data==key)
     {
        return root;
     }


     if(key<root->data)
     {
         return Search(root->left,key);
     }

    return  Search(root->right,key);

}






  Node* minValueNode(Node* current)
  {
           
           while (current->left!=nullptr)
           {
                  current=current->left;
           }

    return current;         

  }



Node*  InorderSuccessor(Node* root, int key)
{
          Node*  current=Search(root,key);


          // key not found in tree,
         if(current==NULL)
         {
             return nullptr;
         }



         // ! Case 1: Node have a right subtree ,so left subtree not cosidered

         if(current->right!=nullptr)
         {
             return   minValueNode(current->right);
         }




         //! case 2: Node does not have any right subtre;

             Node* successor=nullptr;
             Node* ancestor=root;


             while(ancestor!=current)
             {
                 if(current->data > ancestor->data)
                 {

                     // successor still not  find
                     ancestor=ancestor->right;
                     
                 }else{

                     // successor find

                        
                        successor=ancestor;
                        ancestor=ancestor->left;
                     
                    
                 }
             }

        return successor;
}








int main()
{
      Node* root=NULL;
      
      for(int i=1;i<=10;i++)
      {
          root=insertion(root,i);
      }



      cout<<"inorder traverse :  ";
      inorderTraverse(root);
      cout<<endl;

      Node* x=InorderSuccessor(root,8);
      cout<<x->data;
}