// C++ program to find if there is a duplicate
// sub-tree of size 2 or more.
#include<bits/stdc++.h>
using namespace std;


// Structure for a binary tree node
struct Node
{
	char key;
	Node *left, *right;
};

// A utility function to create a new node
Node* newNode(char key)
{
	Node* node = new Node;
	node->key = key;
	node->left = node->right = NULL;
	return node;
}


// This function returns empty string if tree
// contains a duplicate subtree of size 2 or more.
string dupSubUtil(Node *root)
{

    // if this is null
	if(root==NULL) return "";
         
         string one= dupSubUtil(root->left); 
         string two =dupSubUtil(root->right);
         

         //making in order string
         //changing format we can make it preoeder or post oeder
         string add= one+(root->key)+two;
         cout<<add<<endl;
         
        
         
         return add;
}

// Driver program to test above functions
int main()
{
     
	Node *root = newNode('A');
	root->left = newNode('B');
	root->right = newNode('C');
	root->left->left = newNode('D');
	root->left->right = newNode('E');
	root->right->right = newNode('B');
	root->right->right->right = newNode('E');
	root->right->right->left= newNode('D');

//this include tree and leaf tree inorderly
	dupSubUtil(root);
    
      
	
	return 0;
}
