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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> st;
        int num_val = 0;
        TreeNode *curr = root;     
        while(true) {
            while(curr) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top(), st.pop();
            num_val ++;
            if(num_val == k) 
                return curr->val;
            curr = curr->right;
        }
    }
};