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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) {
            return true;
        }
        
        // return (flipEquiv(root1->left, root2->left) &&
        //         flipEquiv(root1->right, root2->right)) || 
        //     (flipEquiv(root1->left, root2->right) &&
        //         flipEquiv(root1->right, root2->left));
        
        stack<pair<TreeNode*, TreeNode*>> st;
        st.push({root1, root2});
        
        while(!st.empty()) {
            auto [n1, n2] = st.top();
            st.pop();
            if ((!n1 && n2) || (n1 && !n2)) {
                return false;
            }

            if (n1 && n2 && (n1->val != n2->val)) {
                return false;
            }
            
            auto l1 = n1->left ? n1->left->val : -1;
            auto l2 = n2->left ? n2->left->val : -1;
            auto r1 = n1->right ? n1->right->val : -1;
            auto r2 = n2->right ? n2->right->val : -1;
            
            // without swap
            if(l1 == l2 && r1 == r2) {
                if (l1 != -1)
                    st.push({n1->left, n2->left});
                if(r1 != -1)
                    st.push({n1->right, n2->right});
            }
            else if(l1 == r2 && r1 == l2) {
                if (l1 != -1)
                    st.push({n1->left, n2->right});
                if (r1 != -1)
                    st.push({n1->right, n2->left});
            } else {
                return false;
            }
        }
        
        return true;
    }
};