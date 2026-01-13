#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node *left;
  Node *right;

  Node(int data)
  {
    this->data = data;
    left = nullptr;
    right = nullptr;
  }
};

//!----------------insertion
Node *insertionBST(Node *&root, int data)
{
  if (root == nullptr)
  {
    return new Node(data);
  }

  if (root->data == data)
    return root;

  if (data < root->data)
  {
    root->left = insertionBST(root->left, data);
  }
  else if (data > root->data)
  {
    root->right = insertionBST(root->right, data);
  }

  return root;
}

void levelOrdereTraversal(Node *root)
{
  if (!root)
    return;

  queue<Node *> que;
  que.push(root);

  while (!que.empty())
  {
    int n = que.size();
    for (int i = 0; i < n; i++)
    {

      Node *front = que.front();
      que.pop();
      cout << front->data << " ";
      if (front->left)
        que.push(front->left);
      if (front->right)
        que.push(front->right);
    }

    cout << endl;
  }
}

//!----------minimum value node
// left most node
int minValue(Node *root)
{

  // base case
  if (root == nullptr)
  {
    return -1;
  }

  Node *curr = root;

  // leftmost node is minimum so we move in BST till
  // left node is not nullptr
  while (curr->left != nullptr)
  {
    curr = curr->left;
  }

  // returning the data at the leftmost node
  return curr->data;
}

//!------- floor value
// quale or ultimate smaller of given x
int floor(Node *root, int x)
{

  // if not get smaller or equal value
  if (root == nullptr)
    return -1;

  // if find equal
  if (root->data == x)
  {
    return x;
  }

  // find smaller of x

  if (root->data > x)
  {
    return floor(root->left, x);
  }

  // code here means: getting first  smaller answer

  // then find greater one in right side
  int val = floor(root->right, x);

  // if not greate value than this node in right side
  if (val == -1)
    return root->data;

  // if get greate value in right side ,take max valure;
  return max(root->data, val);
}





//!----------inorder successor:
// Search a node with given key
Node* Search(Node* root, int key) {
    if (root == nullptr || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return Search(root->left, key);
    }
    return Search(root->right, key);
}

// Return the minimum value node (leftmost node)
Node* minValueNode(Node* current) {
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}

// Inorder Successor in BST
Node* InorderSuccessor(Node* root, int key) {
    Node* current = Search(root, key);

    // Case: key not found in tree
    if (current == nullptr) {
        return nullptr;
    }

    // Case 1: Node has right subtree
    if (current->right != nullptr) {
        return minValueNode(current->right);
    }

    // Case 2: No right subtree – search from root for the successor
    Node* successor = nullptr;
    Node* ancestor = root;
  
    
    while (ancestor != current) {
        if (current->data < ancestor->data) {
            successor = ancestor;
            ancestor = ancestor->left;
        } else {
            //to reach the curent node
            //akhane succesot update hocce na
            //! vvi
            ancestor = ancestor->right;
        }
    }

    return successor;
}



//!-------------------------------- check a bst is bst
//approch : 1
//* inorder approch
//*  set int_min for intial of prev
//* go left dfs and everyy node must be small value than prev
//* if true for cure node upgrade prev

// C++ program to check if a tree is BST
// using Inorder Traversal

#include <iostream>
#include <climits>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Recursive Function for inorder traversal
bool inorder(Node* root, int &prev) {
    if (!root) 
      	return true;

    // Recursively check the left subtree
    if (!inorder(root->left, prev)) 
      	return false;

    // Check the current node value against the previous value
    if (prev >= root->data) 
      	return false;
    
    // Update the previous value to the current node's value
    prev = root->data;

    // Recursively check the right subtree
    return inorder(root->right, prev);
}

// Function to check if the tree is a valid BST
bool isBST(Node* root) {
    int prev = INT_MIN;
    return inorder(root, prev);
}

int main() {
  
    // Create a sample binary tree
    //     10
    //    /  \
    //   5    20
    //        / \
    //       9   25

    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(9);
    root->right->right = new Node(25);

    if (isBST(root))
        cout << "True" << endl;
    else 
        cout << "False" << endl;

    return 0;
}



//! approch 2 : 
//* go right or left as wish
//* set man and maximum range for everynode
//* if node value is in range return true;
// C++ program to check if a tree is BST
// Using specified range of Min and Max Values


// Helper function to check if a tree is BST within a given range
bool isBSTUtil(Node* node, int min, int max) {
    if (node == nullptr) 
      	return true;

    // If the current node's data 
    // is not in the valid range, return false
    if (node->data < min || node->data > max) 
      	return false;

    // Recursively check the left and 
    // right subtrees with updated ranges
    return isBSTUtil(node->left, min, node->data - 1) &&
           isBSTUtil(node->right, node->data + 1, max);
}

// Function to check if the entire binary tree is a BST
bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}




//!--------------- from a sorted array make it bst
Node* sortedArrayToBSTRecur(vector<int>& arr, 
                               int start, int end) {
    if(start > end) return nullptr;
    
    // Find the middle element
    int mid = start + (end - start) / 2;
    
    // Create root node
    Node* root = new Node(arr[mid]);
    
    // Create left subtree
    root->left = sortedArrayToBSTRecur(arr, start, 
                                      mid - 1);
                                      
    // Create right subtree
    root->right = sortedArrayToBSTRecur(arr, mid + 1,
                                       end);
    return root;
}





//!----------------------- greater sum bst
//where all node value will replace with its equal and greter value sum


void convertBSTUtil(Node* root, int &sum) {
    if (root == nullptr) return;

    // Traverse the right subtree first (greater values)
    convertBSTUtil(root->right, sum);

    // Update the current node's value with the cumulative sum
    sum += root->data;
    root->data = sum;

    // Traverse the left subtree
    convertBSTUtil(root->left, sum);
}

Node* modify(Node* root) {
    int sum = 0;
    convertBSTUtil(root, sum);
    return root;
}












int main()
{

  Node *root = nullptr;
  root = insertionBST(root, 25);
  root = insertionBST(root, 23);
  root = insertionBST(root, 33);
  root = insertionBST(root, 26);
  root = insertionBST(root,56);
  root = insertionBST(root, 29);
  root = insertionBST(root, 47);
  root = insertionBST(root, 35);
  root = insertionBST(root, 36);
  root = insertionBST(root, 34);
  root = insertionBST(root, 47);
  root = insertionBST(root, 38);
  root = insertionBST(root, 24);

  levelOrdereTraversal(root);

  Node* insucc=InorderSuccessor(root,38);
  cout<<"succ: ";
  cout<<insucc->data;
  return 0;
}