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
    bool recurse(TreeNode* t1, TreeNode* t2) {
        if(!t1 && !t2) return true;
        if(!t1 || !t2) return false;
        
        return t1->val == t2->val && recurse(t1->left, t2->right) 
            && recurse(t1->right, t2->left);
        // deque<TreeNode*> dq;
        // dq.push_front(root);
        // while(!dq.empty()) {
        //     deque<TreeNode*> tmp;
        //     for(int i = 0, sz = dq.size(); i<sz; i+=2) {
        //         if(!dq.front() && !dq.back()) {
        //             dq.pop_front();
        //             if(!dq.empty()) dq.pop_back();
        //             continue;         // both NULL continue
        //         }
        //         if(!dq.front() || !dq.back()) return false;       // only one is NULL
        //         if(dq.front()->val != dq.back()->val)       // values dont match
        //             return false;
        //         TreeNode* v = dq.front();
        //         dq.pop_front();
        //         tmp.push_front(v->right);
        //         tmp.push_front(v->left);
        //         if(!dq.empty()){
        //             v = dq.back();
        //             dq.pop_back();
        //             tmp.push_back(v->left);
        //             tmp.push_back(v->right);
        //         }
        //     }
        //     dq = tmp;
        // }
        // return true;
    }
    bool isSymmetric(TreeNode* root) {
        return recurse(root, root);
    }
};