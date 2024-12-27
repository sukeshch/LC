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
    int maxSum = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        recurse(root);
        return maxSum;
    }
    
    int recurse(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        int maxLeft = max(recurse(root->left), 0);
        int maxRight = max(recurse(root->right), 0);
        maxSum = max(maxSum, maxLeft + maxRight + root->val);
        return max(maxLeft + root->val, maxRight + root->val);
    }
};