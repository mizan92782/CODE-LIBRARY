// C++ program to delete element in binary tree
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has key, pointer to left
child and a pointer to right child */
struct Node {
	int data;
	struct Node *left, *right;
};

/* function to create a new node of tree and
return pointer */
struct Node* newNode(int key)
{
	struct Node* temp = new Node;
	temp->data = key;
	temp->left = temp->right = NULL;
	return temp;
};

/* Inorder traversal of a binary tree*/
void inorder(struct Node* temp)
{
	if (!temp)
		return;
	inorder(temp->left);
	cout << temp->data << " ";
	inorder(temp->right);
}

struct Node* deletion(struct Node* root, int key)
{
	if (root == NULL)
		return NULL;
	if (root->left == NULL && root->right == NULL) {
		if (root->data == key)
			return NULL;
		else
			return root;
	}
	Node* key_node = NULL;
	Node* temp;
	Node* last;
	queue<Node*> q;
	q.push(root);
	// Do level order traversal to find deepest
	// node(temp), node to be deleted (key_node)
	// and parent of deepest node(last)
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		if (temp->data == key)
			key_node = temp;
		if (temp->left) {
			last = temp; // storing the parent node
			q.push(temp->left);
		}
		if (temp->right) {
			last = temp; // storing the parent node
			q.push(temp->right);
		}
	}
	if (key_node != NULL) {
		key_node->data
			= temp->data; // replacing key_node's data to
						// deepest node's data
		if (last->right == temp)
			last->right = NULL;
		else
			last->left = NULL;
		delete (temp);
	}
	return root;
}
// Driver code
int main()
{


    //https://www.geeksforgeeks.org/deletion-binary-tree/
	struct Node* root = newNode(9);
	root->left = newNode(2);
	root->left->left = newNode(4);
	root->left->right = newNode(7);
	root->right = newNode(8);

	cout << "Inorder traversal before deletion : ";
	inorder(root);

	int key = 7;
	root = deletion(root, key);

	cout << endl;
	cout << "Inorder traversal after deletion : ";
	inorder(root);

	return 0;
}
