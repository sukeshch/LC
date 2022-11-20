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
    bool searchLeft(TreeNode* root, int depth) {
        int d = 0;
        while(root) {
            root = root->left;
            d++;
        }
        if(d == depth) // right exists
            return true;
        return false;
    }
    bool searchRight(TreeNode* root, int depth) {
        int d = 0;
        while(root) {
            root = root->right;
            d++;
        }
        if(d == depth) // right exists
            return true;
        return false;
    }
    
    int recurse(TreeNode* root, int depth) {
        // cout << ((root) ? root->val : 00) << " :@ " << depth << endl;
        if(!root && depth >= 1) return -1;
        if(depth == 1) return 1;
        if(!searchLeft(root, depth))
            return -1;
        if(searchRight(root, depth)) 
            return int(pow(2, depth))-1;
        int ans;
        ans = recurse(root->right, depth-1);
        if(ans != -1) 
            return ans + int(pow(2, depth-1));
        return pow(2, depth-2) + recurse(root->left, depth-1);
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int max_depth = 0;
        TreeNode* left = root;
        while(left) {
            left = left->left;
            max_depth++;
        }
        if(max_depth == 1) return 1;
        return recurse(root, max_depth);
    }
};