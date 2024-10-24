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
    TreeNode* replaceValueInTree(TreeNode* root) {
       
        if (!root ) {
            return root;
        }

        queue<TreeNode*> q;
        q.push(root);

       
        int currsum = root->val;
        int nextsum = 0;

      
        while (!q.empty()) {
            int size = q.size();  
             nextsum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* s = q.front();  
                q.pop();  
               
                s->val = currsum-s->val;  

           int   siblingsum = (s->left ? s->left->val : 0) + (s->right ? s->right->val : 0);

               nextsum+=siblingsum;
                if (s->left) {
                    s->left->val = siblingsum;
                    q.push(s->left);
                }
                if (s->right) {
                    s->right->val = siblingsum;
                    q.push(s->right);
                }
            }

            
            currsum = nextsum;
            
        }

        return root;
    }
};
