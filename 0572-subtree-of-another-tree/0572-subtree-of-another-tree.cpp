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
    
    bool dfs(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot) return true;
        if(root && !subRoot || !root && subRoot) return false;
        
        if(root->val == subRoot->val) {
            return (dfs(root->left, subRoot->left) && 
                        dfs(root->right, subRoot->right));
        }
        return false;
    }
    
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root && !subRoot) return true;
        if(root && !subRoot || !root && subRoot) return false;
        
        if(dfs(root, subRoot))
            return true;
        return 
            isSubtree(root->left, subRoot) || 
            isSubtree(root->right, subRoot);
    }
};