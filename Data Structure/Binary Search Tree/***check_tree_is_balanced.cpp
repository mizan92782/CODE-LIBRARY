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


















// ! ********************* make bst - to - Balance Bst**********


void inorder_BBST(Node* root,vector<Node*>& nodes)
{
      if(root==nullptr) return;

      inorder_BBST(root->left,nodes);
      nodes.push_back(root);
      inorder_BBST(root->right,nodes);
}




Node* BalaceBst_util(vector<Node*>& nodes,int start,int last)
{
     if(start>last)
     {
        return  NULL;
     }

     int middle =(start+last)/2;
    
    // find root node,by bracktraking will get root node


     //! ***creating balace bst root...
     Node* root= nodes[middle];
     
     root->left =BalaceBst_util(nodes,start,middle-1);
     root->right=BalaceBst_util(nodes,middle+1,last);
     
     //! return root;
    return root;

}


Node* BalaceBst(Node* root){


    // * https://www.geeksforgeeks.org/convert-normal-bst-balanced-bst/

     //* for stroing node in sorting order
      vector<Node*>nodes;

      // get sorted node;
      inorder_BBST(root,nodes);

          // now divided nodes in binary search approach,which
          //always give us a middle number of every part
          //thus we get minimum height tree and balacned

      return BalaceBst_util(nodes,0,nodes.size()-1);
}





//! ************* level order traverse********************

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




// ! **************** check a tree is  balanced tre *****************


// ** need Height to check
bool isBalanced(Node* root)
{
    // for height of left subtree
    int lh;
 
    // for height of right subtree
    int rh;
 
    // If tree is empty then return true
    if (root == NULL)
        return 1;
 
    // Get the height of left and right sub trees
    lh = Height(root->left);
    rh = Height(root->right);
 
    if (abs(lh - rh) <= 1 && isBalanced(root->left)
        && isBalanced(root->right))
        return 1;
 
    // If we reach here then tree is not height-balanced
    return 0;
}








//****  not need height coutn......optimize approach

int  isBalanced_2(Node* root)
{
     if(root==NULL) return 0;


    //keft side
     int lh=isBalanced_2(root->left);

     // if we get  one subtere inbalance ,so we dont need to check other or going to right chield,direc go back to root
     if(lh==-1)
     {
        return -1;
     }



     //right side
     int rh=isBalanced_2(root->right);

     // if we get  one subtere inbalance ,so we dont need to check other
     if(rh==-1)
     {
        return -1;
     }


     // if we dont ger in balace left and right side than check between inbalanced for root

     if(abs(lh-rh)>1)
     {
         return -1;
     }

   
     // if no inbalaced ,the return balaned height
     return  max(lh,rh)+1;


}




int main()
{
      Node* root=NULL;
      
      for(int i=1;i<=20;i++)
      {
          root=insertion(root,i);
      }


      printLevelwise(root);
      cout<<endl;

      // balaced check

      if(isBalanced_2(root)==-1)
      {
        cout<<"ther is a inbalanced in the tree :  \n";
      }else{
        cout<<"ther is no inbalanced \n";
      }



      root=BalaceBst(root);

      cout<<endl<<endl<<"after balace : \n";
      printLevelwise(root);
      cout<<endl;

       if(isBalanced_2(root)==-1)
      {
        cout<<"ther is a inbalanced in the tree :  \n";
      }else{
        cout<<"ther is no inbalced \n";
      }



     
}