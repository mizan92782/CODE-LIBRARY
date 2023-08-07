// C++ program to find if there is a duplicate
// sub-tree of size 2 or more.
#include<bits/stdc++.h>
using namespace std;

// Separator node
const char MARKER = '$';

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

unordered_set<string>s;
int x=0;

// This function returns empty string if tree
// contains a duplicate subtree of size 2 or more.
string dupSubUtil(Node *root)
{
	if(root==NULL) return "";
         
         string one= dupSubUtil(root->left); 
         string two =dupSubUtil(root->right);
         
         string add= one+(root->key)+two;
         cout<<add<<endl;
         
         if(s.count(add))
         {
              
            x=1;
         }else
         {
             s.insert(add);
         }
         
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

	string str = dupSubUtil(root);
    
      
	(x == 1) ? cout << " Yes ":
							cout << " No " ;
	return 0;
}
