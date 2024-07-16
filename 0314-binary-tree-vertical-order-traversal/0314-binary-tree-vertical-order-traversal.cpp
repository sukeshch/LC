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
    struct node{
        int row;
        int col;
        TreeNode* tree_node;
    };
    
    vector<vector<int>> verticalOrder(TreeNode* root) {
        if(!root) return {};
        std::map<int,std::vector<int>> cv_map;
        queue<node> q;
        
        q.push({0, 0, root});
        
        while(!q.empty()) {
            for(int sz = q.size(), i=0; i<sz ; i++) {
                auto n = q.front();
                q.pop();
                cv_map[n.col].push_back(n.tree_node->val);
                if(n.tree_node->left)
                    q.push({n.row-1, n.col-1, n.tree_node->left});
                if(n.tree_node->right)
                    q.push({n.row+1, n.col+1, n.tree_node->right});
            }
        }
        vector<vector<int>> result;
        for(auto itr : cv_map) {
            result.push_back(itr.second);
        }
        return result;
    }
};