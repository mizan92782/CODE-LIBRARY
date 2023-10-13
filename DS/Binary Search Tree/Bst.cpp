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



//print given level
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






void leftview_bst(Node* root,int rootcount=1)
{
     if(root==NULL)
     {
        return ;
     }

     if(root!=NULL && rootcount==1)
     {
        cout<<root->data<<" ";
        rootcount++;
     }

     if(root->left)
     {
        cout<<root->left->data<<" ";
     }


     leftview_bst(root->left,rootcount);
     leftview_bst(root->right,rootcount);
}



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



int main()
{

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