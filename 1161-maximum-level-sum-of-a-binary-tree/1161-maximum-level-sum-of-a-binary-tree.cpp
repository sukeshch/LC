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
    int maxLevelSum(TreeNode* root) {
        map<int, int> lsums;
        
        stack<pair<TreeNode*,int>> st;
        st.push({root, 1});
        
        while(!st.empty()) 
        {
            auto v = st.top();
            st.pop();
            
            lsums[v.second] += v.first->val;
            
            if(v.first->right)
                st.push({v.first->right, v.second+1});
            if(v.first->left)
                st.push({v.first->left, v.second+1});
        }
        int max_res = -100009, max_index = 0;
        for(auto lsum : lsums) {
            if(lsum.second > max_res) {
                max_res = lsum.second;
                max_index = lsum.first;
            }
        }
        return max_index;
    }
};