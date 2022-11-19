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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        invertTree(root->left);
        invertTree(root->right);
        std::swap(root->left, root->right);
        // queue<TreeNode*> q;
        // q.push(root->left);
        // q.push(root->right);
        // while(!q.empty())
        // {
        //     auto left = q.front();
        //     q.pop();
        //     auto right = q.front();
        //     q.pop();
        //     cout << (left ? left->val : -1) << " " << (right? right->val : -1) << endl;
        //     std::swap(left, right);
        //     if(left) {
        //         q.push(left->left);
        //         q.push(left->right);
        //     }
        //     if(right) {
        //         q.push(right->left);
        //         q.push(right->right);
        //     }
        // }        
        return root;
    }
};