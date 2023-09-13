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
    
    TreeNode *root;
    
    TreeNode* recurse(vector<int>& preorder, vector<int>& inorder,
        int pre_st, int pre_end, int in_st, int in_end) {
        if(pre_st > pre_end || in_st > in_end)
            return NULL;
        if(pre_st == pre_end) {
            return new TreeNode(preorder[pre_st]);
        }
        TreeNode *node = new TreeNode(preorder[pre_st]);
        
        auto it = find(inorder.begin() + in_st, inorder.begin() + in_end, node->val);
        int in_index = it - inorder.begin();
        
        // left exists - elements presents between start and 
        // node->val 
        int pre_index = pre_st;
        
        if(in_index > in_st) { 
            // use size of left sub tree from inorder 
            // to figure out preorder left, right distinction
            pre_index = pre_st + (in_index - in_st);
            node->left = recurse(preorder, inorder, 
                                pre_st + 1, pre_index,
                                in_st, in_index-1);
        }
        
        // right exists 
        if (in_end > in_index) {
            node->right = recurse(preorder, inorder, 
                                pre_index + 1, pre_end,
                                in_index + 1, in_end);
        }
        
        return node;
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        root = recurse(
            preorder, inorder, 
            0, preorder.size()-1, 
            0, inorder.size()-1
        );
        return root;
    }
};