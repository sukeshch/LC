/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* lowestCommonAncestor(Node* p, Node * q) {
        unordered_map<int, Node*> mp_;
        mp_[p->val] = p;
        mp_[q->val] = q;
        Node* pp = p->parent, *pq = q->parent;
        while(pp || pq) {
            if(pp) {
                if(mp_.count(pp->val) != 0) return mp_[pp->val];
                mp_[pp->val] = pp;
                pp = pp->parent;
            }
            if(pq) {
                if(mp_.count(pq->val) != 0) return mp_[pq->val];
                mp_[pq->val] = pq;
                pq = pq->parent;
            }
        }
        return pp;
    }
};