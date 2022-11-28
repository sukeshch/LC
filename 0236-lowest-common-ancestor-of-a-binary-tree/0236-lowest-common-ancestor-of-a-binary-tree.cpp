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
    bool findNode(TreeNode* root, int val, vector<TreeNode*> &res) {
        if(!root) return false;
        if(root->val == val) {
            res.push_back(root);
            return true;
        }
        if(findNode(root->left, val, res)) {
            res.push_back(root);
            return true;
        }
        if(findNode(root->right, val, res)) {
            res.push_back(root);
            return true;
        }
        return false;
    }
    
    TreeNode* lca(vector<TreeNode*> p, vector<TreeNode*> q) {
        // p > q
        TreeNode* res = p.back();
        for(int i=q.size()-1, j = p.size()-1; i>=0; i--, j--) {
            if(p[j]->val == q[i]->val)
                res = p[j];
            else 
                break;
        }
        return res;
    }
           
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> ppath = vector<TreeNode*>(), qpath = vector<TreeNode*>(); 
        findNode(root, p->val, ppath);
        findNode(root, q->val, qpath);
        if(ppath.size() > qpath.size())
            return lca(ppath, qpath);
        return lca(qpath, ppath);
    }
};