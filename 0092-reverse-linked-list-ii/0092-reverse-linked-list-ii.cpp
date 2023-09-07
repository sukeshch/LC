/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int l, int r) {
        if(l == r) return head;
        
        ListNode* root = new ListNode();
        root->next = head;
        
        ListNode* left, *right, *left_prev, *right_next, *curr = root, *prev;
        int pos = 0;
        while(pos <= r) {
            if(pos == (l-1)) {
                left_prev = curr;
                left = curr->next;
            }
            if(l < pos && pos <= r) {
                if(pos == r) {
                    right = curr;
                    right_next = curr->next;
                }
                auto temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            } else {
                prev = curr;
                curr = curr->next;
            }
            pos++;
        }
        
        left_prev->next = right;
        left->next = right_next;
        
        return root->next;
    }
};