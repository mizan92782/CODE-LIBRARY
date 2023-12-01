//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    bool util(Node* root, int minValue, int maxValue) {
    if (root == NULL) {
        return true;
    }

    // Check if the current node's value is within the valid range
    if (root->data <= minValue || root->data >= maxValue) {
        return false;
    }

    // Check the left and right subtrees recursively with updated min and max values
    bool left = util(root->left, minValue, root->data);
    bool right = util(root->right, root->data, maxValue);

    // Return true only if both subtrees are valid BSTs
    return left && right;
}



bool isBST(Node* root) {
    //https://www.geeksforgeeks.org/a-program-to-check-if-a-binary-tree-is-bst-or-not/
    // Call the util function with initial min and max values
    return util(root, INT_MIN, INT_MAX);
}

int countnode(Node* root)
{
     
     if(root==NULL) return 0;
     
     return 1+countnode(root->left)+countnode(root->right);
     
}

void findbst(Node* root,int& count)
{
     if(root==NULL) return;
     
     findbst(root->left,count);
     
     if(isBST(root) && countnode(root)>count)
     {
         count=countnode(root);
     }
    
     
     findbst(root->right,count);
}



    int largestBst(Node *root)
    {
    	//Your code here
    	
    	int count=0;
    	
    	 findbst(root,count);
    	
    	
    return count;
    }
};


//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {
    //https://www.geeksforgeeks.org/largest-bst-binary-tree-set-2/
   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.largestBst(root) << endl;
    }
    return 0;
}

// } Driver Code Ends