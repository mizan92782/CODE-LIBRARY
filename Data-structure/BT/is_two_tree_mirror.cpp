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






bool isMirror(Node* one,Node* two)
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




      return (one->data==two->data) && isMirror(one->right,two->left) &&  isMirror(one->left,two->right) ;
}






/*
 * * iterative way
*/

bool isMirror_stl(Node* one,Node* two)
{
     if(one==NULL && two==NULL)
     {
       return true;
     }


     if(one==NULL || two==NULL)
     {
      return false;
     }



     queue<Node*>oneQue;
     oneQue.push(one);
     
     queue<Node*> twoQue;
     twoQue.push(two);


     while (!oneQue.empty() &&  !twoQue.empty())
     {
               Node* x =oneQue.front();
               Node* y= twoQue.front();

               oneQue.pop();
               twoQue.pop();


               if(x->data != y->data)
               {
                return false;
               }

                // * cheking 
               if(x->right  &&  y->left)
               {
                   oneQue.push(x->right);
                   twoQue.push(y->left);
               }else if (x->right || y->left)
               {
                   return false;
               }


                // * cheking 
               if(x->left  && y->right)
               {
                   oneQue.push(x->left);
                   twoQue.push(y->right);
               }else if (x->left || y->right)
               {
                   return false;
               }



              
     }


     return true;
     


}



int main()
{
 
    //! its like to same tree cheking,only difference is we cheking anti-node are same or not
    //https://www.geeksforgeeks.org/check-if-two-trees-are-mirror/



    // * First tree
    Node *a = newNode(1);
    Node *b = newNode(1);
    a->left = newNode(2);
    a->right = newNode(3);
    a->left->left  = newNode(4);
    a->left->right = newNode(5);
 
    b->left = newNode(3);
    b->right = newNode(2);
    b->right->left = newNode(5);
    b->right->right = newNode(4);






    // * Cheking Tree are same
    if(isMirror(a,b))
    {
        cout<<"Tree are same "<<endl;
    }else{
         cout<<"Tree are not same"<<endl;
    }


    // * Stl
    if(isMirror_stl(a,b))
    {
        cout<<"Tree are same "<<endl;
    }else{
         cout<<"Tree are not same"<<endl;
    }



     // * Changing one value
       a->left->left= newNode(10);


    






// * Cheking Tree are same
     if(isMirror(a,b))
    {
        cout<<"Tree are same "<<endl;
    }else{
         cout<<"Tree are not same"<<endl;
    }




     // * Stl
    if(isMirror_stl(a,b))
    {
        cout<<"Tree are same "<<endl;
    }else{
         cout<<"Tree are not same"<<endl;
    }



    return 0;
     
}