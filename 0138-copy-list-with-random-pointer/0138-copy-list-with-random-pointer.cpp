/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        Node *orig = head;
        Node *root = new Node(-1);
        
        map<Node*, Node*> old_new_mp;
        
        Node* current = root;
        while(orig != nullptr) {
            current->next = new Node(orig->val);
            
            old_new_mp[orig] = current->next;
            
            orig = orig->next;
            current = current->next;
        }
        
        orig = head;
        current = root->next;
        while(orig != nullptr) {
            if(orig->random != nullptr)
                current->random = old_new_mp[orig->random];
            
            current = current->next;
            orig = orig->next;
        }
        
        return root->next;
    }
};