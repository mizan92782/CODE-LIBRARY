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



int height(Node* root)
{
    //calcualte level
    if(root==NULL)
    {
        return 0;
    }


    return 1+max(height(root->right),height(root->left));
}



//printlevel
void printLevelOrder(Node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++)
        printCurrentLevel(root, i);
}
 
// Print nodes at a current level
void printCurrentLevel(Node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        cout << root->data << " ";
    else if (level > 1) {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}


int main()
{

     struct Node* root=NULL;
      root= createNewNode(4);
      root->right=createNewNode(5);
      root->left=createNewNode(6);
      root->right->right= createNewNode(66);
      root->left->left=createNewNode(44);
      
     



      printLevelOrder(root);


}