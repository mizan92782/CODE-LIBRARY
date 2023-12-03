// CPP program to find distance between
// two nodes in BST
#include <bits/stdc++.h>
using namespace std;

struct Node {
	struct Node* left, *right;
	int key;
};

struct Node* newNode(int key)
{
	struct Node* ptr = new Node;
	ptr->key = key;
	ptr->left = ptr->right = NULL;
	return ptr;
}

// Standard BST insert function
struct Node* insert(struct Node* root, int key)
{
	if (!root)
		root = newNode(key);
	else if (root->key > key)
		root->left = insert(root->left, key);
	else if (root->key < key)
		root->right = insert(root->right, key);
	return root;
}





// ! ******************** Distance of two nodes **********


int distance(Node* root, int a)
{
     int path=0;
     while (root->key!=a)
     {
           if(a > root->key)
           {
            root=root->right;
           }else{
            root=root->left;
           }

           path++;
     }

     return path;
     
}
int distanceUtil(Node* root,int minv,int maxv)
{
         // tree is null or reach to a leaf that means not find both values
          if(root==NULL) return 0;


        // if both nodes lies in left chield
        if(minv > root->key  && maxv > root->key)
        {
             return  distanceUtil(root->left,minv,maxv);
        }



         // if both nodes lies in right chield
        if(minv < root->key  && maxv < root->key)
        {
             return  distanceUtil(root->right,minv,maxv);
        }


        //! if we get two value and this root is LCA of these nodes

          // ! if we dont use this condition,if two nodes will same its not work for that
         if(minv < root->key && maxv > root->key)
         {
             return distance(root,minv) + distance(root,maxv);
         }


 return 0;

}

int distanceofnodes(Node* root,int a, int b)
{

    // **idectify max and min value
     int x=a;
     int y=b;

     a=min(x,y);
     b=max(x,y);


     return distanceUtil(root,a,b);





}

// Driver code
int main()
{
	struct Node* root = NULL;
	root = insert(root, 20);
	insert(root, 10);
	insert(root, 5);
	insert(root, 15);
	insert(root, 30);
	insert(root, 25);
	insert(root, 35);
	int a = 5, b = 55;
	cout << distanceofnodes(root, 20,20);
	return 0;
}
