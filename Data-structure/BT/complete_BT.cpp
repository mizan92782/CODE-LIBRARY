#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *right;
    Node *left;
};

Node *createNewNode(int data)
{
    Node *node = new Node;
    node->data = data;
    node->left = node->right = NULL;

    return node;
}

void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->right);
    preOrder(root->left);
}

bool is_complete_tree_Stl(Node *root)
{
    queue<Node *> que;

    que.push(root);

    bool non_full = false;

    while (!que.empty())
    {
        Node *x = que.front();
        que.pop();

        if (x->left)
        {

            // agai non full paoya gale,aber
            // noder chield,thaka mane ata non leaf node
            if (non_full == true)
            {
                return false;
            }

            que.push(x->left);
        }
        else
        {
            non_full = true;
            // non full  paoya gace.....
        }

        if (x->right)
        {

            // agai non full paoya gale,aber
            // noder chield,thaka mane ata non leaf node
            if (non_full == true)
            {
                return false;
            }

            que.push(x->right);
        }
        else
        {
            non_full = true;
            // non full  paoya gace.....
        }
    }

    return true;
}







//approch 2
bool isCompleteBT_stl(Node* root)
{
    
// Create an empty queue
    queue<Node*> q;
    q.push(root);
    // Create a flag variable which will be set true
    // when a non null node is seen
    bool flag = false;
 
    // Do level order traversal using queue.
    // enQueue(queue, &rear, root);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
 
        if (temp == NULL) {
            // If we have seen a NULL node, we set the flag
            // to true
            flag = true;
        }
        else {
            // If that NULL node is not the last node then
            // return false
            if (flag == true) {
                return false;
            }
            // Push both nodes even if there are null
            q.push(temp->left);
            q.push(temp->right);
        }
    }
 
    // If we reach here, then the tree is complete Binary
    // Tree
    return true;
}
 


 //approch 3

 int countNode(Node* root)
 {
    if(root==NULL) return 0;

    return 1+countNode(root->right)+countNode(root->left);
 }


bool iscomplete_Bt(Node* root,int index,int nodeNum)
{

    //https://www.geeksforgeeks.org/check-whether-binary-tree-complete-not-set-2-recursive-solution/

    // if its null not checking index
    if(root==NULL)
    {
        return true;
    }

    if(index>=nodeNum)
    {
        return false;
    }

    return iscomplete_Bt(root->left,index*2+1,nodeNum) &&  iscomplete_Bt(root->right,index*2+2,nodeNum) ;
}
int main()
{
    
    //https://www.geeksforgeeks.org/check-if-a-given-binary-tree-is-complete-tree-or-not/
    struct Node *root = NULL;
    root = createNewNode(1);
    root->right = createNewNode(2);
    root->left = createNewNode(3);
    root->right->left = createNewNode(4);

    if (is_complete_tree_Stl(root))
    {
        cout << "its a complete binary tree\n";
    }
    else
    {
        cout << "ist not a complete bianry tree\n";
    }



  //approch: 3
  int countNode_num=countNode(root);
  if(iscomplete_Bt(root,0,countNode_num))
  {
    cout<<"its complete  B tree\n";

  }else{
    cout<<"its not complete  B tree\n";
  }

   

    
}