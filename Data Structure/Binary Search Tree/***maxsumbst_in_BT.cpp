// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Binary tree node
struct Node {
	struct Node* left;
	struct Node* right;
	int data;

	Node(int data)
	{
		this->data = data;
		this->left = NULL;
		this->right = NULL;
	}
};

// Information stored in every
// node during bottom up traversal
struct Info {

	// Max Value in the subtree
	int max;

	// Min value in the subtree
	int min;

	// If subtree is BST
	bool isBST;

	// Sum of the nodes of the sub-tree
	// rooted under the current node
	int sum;

	// Max sum of BST found till now
	int currmax;
};

// Returns information about subtree such as
// subtree with maximum sum which is also a BST
Info MaxSumBSTUtil(struct Node* root, int& maxsum)
{
	// case 1 : null root node;
	if(root==nullptr) return {INT_MIN,INT_MAX,true,0,0};

	// case 2 : null root is leaf
	if(root->left==NULL && root->right == nullptr)
	{
		 maxsum=max(maxsum,root->data);
		 return { root->data ,root->data, true,root->data,maxsum};
	}


	//to left node
	Info L =MaxSumBSTUtil(root->left,maxsum);
	//to right node 
	Info R = MaxSumBSTUtil(root->right,maxsum);



    // ! after goint to left and right ,we get al information bot right and left

    // !check then the root node of left nad right


	Info Bst;


	//! cheking ther root node bst or not

	 if(L.max< root->data && R.min> root->data && L.isBST && R.isBST)
	 {
		 // so root is bst
		 Bst.isBST=true;

        //update value;

		Bst.max=max(root->data,max(L.max,R.max));
		Bst.min=min(root->data,min(L.min,R.min));


		// ! inportant part:
		maxsum=max(maxsum,L.sum+root->data,R.sum);
		

		//updat root node sum value;
		Bst.sum=L.sum+root->data+R.sum;


		// so as it is bst,track the current best sum

		Bst.currmax=maxsum;


         // return node to child of previous recurison
		return Bst;


	 }

	




    // if not bst
	 Bst.isBST=false;
	 Bst.currmax=maxsum;
	 Bst.sum=L.sum+root->data+R.sum;


	return Bst;

	
	
}

// Function to return the maximum
// sum subtree which is also a BST
int MaxSumBST(struct Node* root)
{
	int maxsum = INT_MIN;
	return MaxSumBSTUtil(root, maxsum).currmax;
}

// Driver code
int main()
{

	//https://www.geeksforgeeks.org/maximum-sub-tree-sum-in-a-binary-tree-such-that-the-sub-tree-is-also-a-bst/
	
	struct Node* root = new Node(5);
	root->left = new Node(14);
	root->right = new Node(3);
	root->left->left = new Node(6);
	root->right->right = new Node(7);
	root->left->left->left = new Node(9);
	root->left->left->right = new Node(1);

	cout << MaxSumBST(root);

	return 0;
}
