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
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> st;
        int depth = 1;
        st.push(root);
        while(!st.empty()) {
            for(int sz = st.size(), i = 0; i<sz; i++) {
                auto p = st.front();
                st.pop();
                if(!p->left && !p->right) return depth;
                if(p->left) st.push(p->left);
                if(p->right) st.push(p->right);
            }
            depth++;
        }
        
        return depth;
    }
};