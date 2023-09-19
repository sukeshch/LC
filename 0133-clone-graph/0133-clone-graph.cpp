/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* mp_[102] = {NULL};
    bool visited[102]{false};
    Node* root;
    
    void deepCopy(Node* node) {
        if(visited[node->val]) // avoid multiple recursions with same node
            return;
        // cout << __func__ << node->val << endl;
        
        if(mp_[node->val] == NULL) 
            mp_[node->val] = new Node(node->val);
        visited[node->val] = true;
        
        mp_[node->val]->neighbors.resize(node->neighbors.size());
        int cnt = 0;
        // cout << "childs " << node->val << endl;
        for(int i = 0; i < node->neighbors.size(); i++) {
            if ( mp_[node->neighbors[i]->val] == NULL ) {
                mp_[node->neighbors[i]->val] = new Node(node->neighbors[i]->val);
            }
            mp_[node->val]->neighbors[i] = mp_[node->neighbors[i]->val];
            // cout << "childs of " << node->val << " i " << i << " val= " << node->neighbors[i]->val << endl;
        }
        
        for(int i = 0; i < node->neighbors.size(); i++) {
            // cout << "recurse " << endl;
            if(!visited[node->neighbors[i]->val]) {
                // cout << "recurse call on " << node->neighbors[i]->val << endl;
                deepCopy(node->neighbors[i]);
            }
        }
        
    }
    
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        deepCopy(node);
        return mp_[node->val];
    }
};