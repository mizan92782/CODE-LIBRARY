#include<bits/stdc++.h>
using namespace std;
 
struct Node
{
    int data;
    struct Node* left, *right;
};
 
// utility function to create a new node
struct Node* newNode(int x)
{
    struct Node* temp = new Node;
    temp->data = x;
    temp->left = temp->right = NULL;
    return temp;
};



//count node of tree;

int count(Node*  root)
{
    if(root==NULL) return 0;
    return 1+count(root->right)+count(root->left);

}




bool checkDibition(Node* root,int n)
{
      if(root==NULL)
      {
        return false;
      }



      if (count(root) == n-count(root))
        return true;

      return  checkDibition(root->right,n) || checkDibition(root->left,n);

}



bool checkEdge(Node* root)
{
     int n= count(root);
    return checkDibition(root,n);
}







int main()
{

    //https://www.geeksforgeeks.org/check-if-removing-an-edge-can-divide-a-binary-tree-in-two-halves/
    struct Node* root = newNode(5);
    root->left = newNode(1);
    root->right = newNode(6);
    root->left->left = newNode(3);
    root->right->left = newNode(7);
    root->right->right = newNode(4);
 
    checkEdge(root)?  printf("YES") : printf("NO");
 
    return 0;
}