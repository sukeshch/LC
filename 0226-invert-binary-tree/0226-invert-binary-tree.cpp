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
        // invertTree(root->left);
        // invertTree(root->right);
        // std::swap(root->left, root->right);
        queue<TreeNode*> q;
        // TreeNode* prev = root;
        q.push(root);
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            std::swap(p->left, p->right);
            if(p->left) {
                q.push(p->left);
            }
            if(p->right) {
                q.push(p->right);
            }
        }
        // std::swap(root->left, root->right);
        // cout << root->left->val<< "," << root->right->val <<endl;
        
        return root;
    }
};