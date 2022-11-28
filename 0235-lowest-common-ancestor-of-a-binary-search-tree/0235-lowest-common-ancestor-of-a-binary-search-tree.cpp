/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int min = root->val, max = root->val;
        int smin = std::min(p->val, q->val);
        int smax = std::max(p->val, q->val);
        while(root) {
            if(smin < root->val && smax < root->val) {
                root = root->left;
            } else if(smin > root->val && smax > root->val) {
                root = root->right;
            }
            else {
                return root;
            }
        }
        return root;
    }
};