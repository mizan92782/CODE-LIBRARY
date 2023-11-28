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





 int x(Node* node)
    {
        if (node == NULL)
        return 0;
    else {
        /* compute the depth of each subtree */
        int lDepth = x(node->left);
        int rDepth = x(node->right);
 
        /* use the larger one */
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
    }
    bool isBalanced(Node* root) {

        if(root==NULL)
        {
            return true;
        }


        int l=x(root->left);
         int r=x(root->right);

        if(abs(l-r)>1)
        {
            return false;
        }
        

        return  isBalanced(root->left) &&  isBalanced(root->right);
    }










int main()
{

     struct Node* root=NULL;
      root= createNewNode(1);
      root->right=createNewNode(2);
      root->left=createNewNode(3);
      root->right->right= createNewNode(4);
      root->left->left=createNewNode(5);
      
      insertion(root,6);
      insertion(root,7);
      insertion(root,8);
      insertion(root,9);
      insertion(root,10);
      insertion(root,11);



      preOrder(root);

       cout<<endl;
      if(checking_full_binaryTree(root))
      {
        cout<<"its a full Binary tree\n";
      }else{
         cout<<"its not a full binary tree\n";
      }


}