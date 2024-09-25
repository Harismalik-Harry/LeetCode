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
    void helper(TreeNode * root,vector<int> *array)
    {
        if(!root)
        {
            return;
        }
        helper(root->left,array);
        array->push_back(root->val);
        helper(root->right,array);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)
        {
            return {};
        }
        vector<int> array;
         helper(root,&array);
        return array;
    }
};