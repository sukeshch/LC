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
    int max_path = 0;
    
    int recurse(TreeNode* root, int prev) {
        if(root == nullptr) return 0;
        
        int left_path = recurse(root->left, root->val);
        int right_path = recurse(root->right, root->val);
        
        max_path = max(max_path, left_path + right_path);
        
        return root->val == prev ? max(left_path, right_path) + 1 : 0;
    }
    
    
    int longestUnivaluePath(TreeNode* root) {
        recurse(root, -1001);
        return max_path;
    }
};