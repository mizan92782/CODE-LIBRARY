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


Node* insertion(Node* root,int data)
{
    if(root==NULL) 
    {
        root=createNewNode(data);
        return  root;
    }

   
    
    if(root->data> data)
    {
         root->left=insertion(root->left,data);
    }else{
        root->right=insertion(root->right,data);
    }


    return root;
    
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



//! ***************print level ******


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


 //! ********** leaf- non leaf ************
void printLeafNode(Node* root)
{
     if(root->right==NULL && root->left==NULL)
     {
        cout<<root->data<<" ";
        return;
     }

     if(root->right) printLeafNode(root->right);
     if(root->left) printLeafNode(root->left);
}

void printNonLeafNode(Node* root)
{
     // Base Cases
    if (root == NULL
        || (root->left == NULL
            && root->right == NULL))
        return;
  
    // If current node is non-leaf,
    if (root->left != NULL
        || root->right != NULL) {
        cout <<" "<< root->data;
    }
  
    // If root is Not NULL and its one
    // of its child is also not NULL
    printNonLeafNode(root->left);
    printNonLeafNode(root->right);
}






void RightView_bst(Node* root)
{
    if(root==nullptr)
    {
        return;
    }

    if(root->right==NULL && root->left==nullptr)
    {
         cout<<root->data<<" ";
         return;
    }else if(root->right!=NULL )
    {
         cout<<root->data<<" ";
         RightView_bst(root->right);
         if(root->left) RightView_bst(root->left);
    }

}




// ! ************************ Deletion**************************

Node* deletion(Node* root,int data)
{
      // recursive terminated
     if(root==NULL)
     {
        return root;
     }


     if(data>root->data)
     {
        root->right=deletion(root->right,data);
        return root;
     }else if(data<root->data)
     {
        root->left=deletion(root->left,data);
        return root;
     }else{

          // *if find value;


         // * case -1 : if node is leaf node;
         if(root->right==NULL && root->left==NULL)
         {
            delete(root);
            return NULL;
         }



         // * case -2 : if node has one chield
           if(root->right==NULL)
           {
                  Node* temp=root->left;
                  delete(root);
                  return temp;
            
           }else if(root->left==NULL)
           {
               Node* temp=root->right;
               delete(root);
               return temp;
           }

         

          //* case 3 :  node has tow chield\
           
           //store  for successor immediate parent to assig null;
           Node* successor_parent=root;
           
           //store for succssor
           Node* successor=root->right;
           while (successor->left!=NULL)
           {
               successor_parent=successor;
               successor=successor->left;
           }
           
 
            
        if(successor_parent != root)
            successor_parent->left = successor->right;
            // succesor right tree assing as suc_parent left 
            // and in this way,succeseor will deleted from this section
        else
            successor_parent->right = successor->right;
            // 
 
        // Copy Successor Data to root
        root->data = successor->data;
 
        // Delete Successor and return root
        delete successor;

            return root;

           
           


      
          



     }


return root;


}










// User function Template for C


struct Node* minvalue(struct Node* root)
  {
     while (root->left!=NULL)
     {
         root=root->left;
     }

     return root;
     
  }
  
  
struct Node* deleteNode(struct Node* root, int key)
{
    
     if(root==NULL) return NULL;

     if(key<root->data)
     {
       root->left=deleteNode(root->left,key);
     }else if(key>root->data)
     {
       root->right=deleteNode(root->right,key);
     }else{
        
          if(root->right==NULL && root->left==NULL)
          {
            return NULL;
          } 


          if(root->right==NULL && root->left!=NULL)
          {
               return root->left;
          }

          if(root->left==NULL && root->right!=NULL)
          {
             return root->right;
          }


          /*
            !important part
            ! in this code,we actually make deleted nodes->right  as rooot of tree
            ! and make deleted node->left  as the left nodes of inoreder succeser
            ! bcz inorder successor alwaus greter than all  left nods of deleted node
            */

          if(root->right!=NULL && root->left!=NULL)
          {
              struct  Node* xx=root->left;
               root->left=NULL;
              struct Node* x=minvalue(root->right);

               x->left=xx;
               return root->right;
               
               
              
          }

     }

     return root;

    
}



 //! **************** Searching element ************

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




 Node* SearchIteratively(Node* root,int key)
 {
     

      while (root!=NULL)
      {
         if(root==nullptr || root->data==key) return root;

         if(key>root->data)
         {
            root=root->right;
         }else{
             root=root->left;
         }
      }
     

    return root;
 }




  Node* minValueNode(Node* current)
  {
           
           while (current->left!=nullptr)
           {
                  current=current->left;
           }

    return current;         

  }



int main()
{



     //https://www.geeksforgeeks.org/introduction-to-binary-search-tree-data-structure-and-algorithm-tutorials/
     struct Node* root=NULL;

    root = insertion(root, 50);
    insertion(root, 30);
    insertion(root, 20);
    insertion(root, 10);
   
    ;



      preOrder(root);
        
        root=deletion(root,50);
      cout<<endl;
      preOrder(root);
      cout<<endl;

      cout<<SearchIteratively(root,10)->data;
      
      
      /*

      out<<endl;
      cout<<"print given level :  ";
      printGivenLevel(root,3);

      cout<<"\n print leaf Node : ";
      printLeafNode(root);


      cout<<"\nprint non leaf node : ";
     printNonLeafNode(root);

    */
     


}