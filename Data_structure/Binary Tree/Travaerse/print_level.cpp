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

void printcurrentlevel(Node* root,int i);



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
void printLevel(Node* root)
{
    int h = height(root);
    int i;
    for (i = 1; i <= h; i++){
        cout<<"level : "<<i<<" -> ";
        printcurrentlevel(root, i);
        cout<<endl;
    }
}


// printcurrnt level,
// its recursively decrese level upto its reah level=1,actullay
// such way,its reach to i level
void printcurrentlevel(Node* root,int level)
{
       
       if(root==NULL)
       {
        return ;
       }


       if(level==1)
       {
        cout<<root->data<<" ";
       }else
       {
         printcurrentlevel(root->left,level-1);
         printcurrentlevel(root->right,level-1);
       }

}








//************
// Iterative method to find height of Binary Tree
void levelOrder_stl(Node *root)
{
    if (root == NULL) return;
 
    // Create an empty queue for
    // level order traversal
    queue<Node *> q;
     
    // to store front element of
    // queue.
    Node *curr;
 
    // Enqueue Root and NULL node.
    q.push(root);
    q.push(NULL);
 
    while (q.size() > 1)
    {
        curr = q.front();
        q.pop();
         
        // condition to check
        // occurrence of next
        // level.
        if (curr == NULL)
        {
           q.push(NULL);
           cout << "\n";
        }
         
        else {
             
            // pushing left child of
            // current node.
            if(curr->left)
            q.push(curr->left);
             
            // pushing right child of
            // current node.
            if(curr->right)
            q.push(curr->right);
             
            cout << curr->data << " ";
        }
    }
}
 
int main()
{

    //https://www.geeksforgeeks.org/level-order-traversal-line-line-set-3-using-one-queue/

    struct Node* root=NULL;
      root= createNewNode(1);
      root->left=createNewNode(2);
      root->right=createNewNode(3);
      root->left->left= createNewNode(4);
      root->left->right=createNewNode(5);
      root->right->left=createNewNode(6);
      root->right->right=createNewNode(7);
      
     
     



      levelOrder_stl(root);


}