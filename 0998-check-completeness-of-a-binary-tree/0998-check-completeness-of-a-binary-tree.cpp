/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // Function to count the number of nodes in the binary tree
    int countNodes(TreeNode *root) {
        if (!root) {
            // If the root is null, there are no nodes
            return 0;
        }
        // Recursively count the nodes in the left and right subtrees and add 1 for the current node
        return countNodes(root->left) + countNodes(root->right) + 1;
    }

    // Helper function to check if the tree is complete
    bool helper(int i, TreeNode *root, int size) {
        if (!root) return true;//Null Nodes are considered to be CBT
        if (i >= size) return false; //at some point if i>=size it means it is not complete binary tree
        bool leftChild = helper(2*i+1, root->left, size);
        bool rightChild = helper(2*i+2, root->right, size);
        return leftChild && rightChild;
    }

    
    bool isCompleteTree(TreeNode* root) {
        // First, count the number of nodes in the binary tree
        // In a complete binary tree, all nodes at the last level should be as far left as possible
        // If we traverse the tree in level-order, there shouldn't be any null nodes between non-null nodes
        // At any point during the traversal, if index >= number of nodes, it means it's not complete
        int count = countNodes(root);
        return helper(0, root, count);
    }
};