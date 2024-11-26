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
    TreeNode* balanceBST(TreeNode* root) {
        vector<TreeNode*> sorted_nodes;
        
        stack<TreeNode*> st;
        TreeNode* curr = root;
        
        while(curr != nullptr || !st.empty()) {
            
            while(curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }
            
            curr = st.top();
            sorted_nodes.push_back(st.top());
            st.pop();
            
            curr = sorted_nodes.back()->right;
        }
        for(auto s : sorted_nodes)
        {
            cout << s->val << ", ";
        }
        cout << endl;
        return createBST(sorted_nodes, 0, sorted_nodes.size()-1);
    }
    
    TreeNode* createBST(vector<TreeNode*> sorted_nodes, int left, int right)
    {
        // cout << left << " : " << right << " || ";
        if (left > right) return nullptr;
        
        int mid = (left + right) / 2;    
        
        TreeNode* leftTree = createBST(sorted_nodes, left, mid-1);
        TreeNode* rightTree = createBST(sorted_nodes, mid+1, right);
        
        return new TreeNode(sorted_nodes[mid]->val, leftTree, rightTree);
    }
};