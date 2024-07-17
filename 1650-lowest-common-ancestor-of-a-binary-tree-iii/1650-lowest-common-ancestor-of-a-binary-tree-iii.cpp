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
        unordered_map<int, Node*> val_node_map;
        
        while(p != NULL) {
            val_node_map[p->val] = p;
            cout << p->val << " visited \n";
            p = p->parent;            
        }
        
        while(q) {
            if(val_node_map.count(q->val) != 0) {
                return val_node_map[q->val];
            }
            val_node_map[q->val] = q;
            q = q->parent;
        }
        
        return nullptr;
    }
};