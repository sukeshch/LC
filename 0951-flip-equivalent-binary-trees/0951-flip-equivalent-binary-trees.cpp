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
        if (!root1 && root2 || root1 && !root2) {
            return false;
        }
        
        if (root1->val != root2->val) {
            return false;
        }
        
        return (flipEquiv(root1->left, root2->left) &&
                flipEquiv(root1->right, root2->right)) || 
            (flipEquiv(root1->left, root2->right) &&
                flipEquiv(root1->right, root2->left));
        
        /*
        auto l1 = root1->left->val;
        auto l2 = root2->left->val;
        auto r1 = root1->right->val;
        auto r2 = root2->right->val;
        
        // without swap
        if(l1 == l2 && r1 == r2) {
            return 
                flipEquiv(root1->left, root2->left) &&
                flipEquiv(root1->right, root2->right);
        }
        else if(l1 == r2 && r1 == l2) {
            return 
                flipEquiv(root1->left, root2->right) &&
                flipEquiv(root1->right, root2->left);
        } else {
            return false;
        }
        */
    }
};