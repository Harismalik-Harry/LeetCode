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
    // Helper function to find the parent and depth of a given node value
    void findparent(TreeNode *root, TreeNode *parent, int depth, int val, TreeNode *&p, int &h) {
        if (!root) return;

        if (root->val == val) {
            p = parent;  // Store the parent of the found node
            h = depth;   // Store the depth of the found node
            return;
        }

        // Recursively search in the left and right subtrees
        findparent(root->left, root, depth + 1, val, p, h);
        findparent(root->right, root, depth + 1, val, p, h);
    }

    bool isCousins(TreeNode* root, int x, int y) {
        if (!root) return false;

        int xh = -1;             // x's depth
        int yh = -1;             // y's depth
        TreeNode *xp = nullptr;  // x's parent
        TreeNode *yp = nullptr;  // y's parent

        // Call helper to find the parents and depths of x and y
        findparent(root, nullptr, 0, x, xp, xh);
        findparent(root, nullptr, 0, y, yp, yh);

        // Cousins must have the same depth but different parents
        return (xp != yp) && (xh == yh);
    }
};
