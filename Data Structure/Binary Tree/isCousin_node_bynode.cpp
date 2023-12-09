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



// find function for find level of  a node;

int Level(Node* root,Node* a,int lev)
{
     if(root==NULL) return 0;
     if(root==a) return lev;
     
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
bool isSibling(struct Node* root, struct Node* a,
              struct Node* b)
{
    // Base case
    if (root == NULL)
        return false;
 
    return ((root->left == a && root->right == b)
            || (root->left == b && root->right == a)
            || isSibling(root->left, a, b)
            || isSibling(root->right, a, b));
}



bool isCousin(Node* root,Node* a,Node* b)
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



    struct Node *Node1, *Node2;
    Node1 = root->left->left;
    Node2 = root->right->right;
     

    if (isCousin(root, Node1, Node2))
        printf("Yes\n");
    else
        printf("No\n");

     


}