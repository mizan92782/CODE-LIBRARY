#include <iostream>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to find the maximum value node in a BST
TreeNode* findMax(TreeNode* root) {
    while (root->right != nullptr) {
        root = root->right;
    }
    return root;
}

// Function to find the predecessor of a given node in a BST
TreeNode* findPredecessor(TreeNode* root, int key) {
    TreeNode* predecessor = nullptr;

    while (root != nullptr) {
        if (root->val < key) {
            predecessor = root;  // Update predecessor and move to the right subtree
            root = root->right;
        } else {
            root = root->left;   // Move to the left subtree
        }
    }

    return predecessor;
}

int main() {
    // Example usage
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->left = new TreeNode(12);
    root->right->right = new TreeNode(18);

    int key = 7;

    TreeNode* predecessor = findPredecessor(root, key);

    if (predecessor != nullptr) {
        std::cout << "Predecessor of " << key << " is: " << predecessor->val << std::endl;
    } else {
        std::cout << "No predecessor found for " << key << std::endl;
    }

    // Don't forget to free the allocated memory to prevent memory leaks
    // (not shown in this simple example for brevity)

    return 0;
}
