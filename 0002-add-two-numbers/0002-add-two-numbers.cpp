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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* l1_start = l1, *l2_start = l2;
        int carry = 0;
        ListNode* ret; 
        ListNode *prev_l1, *prev_l2;
        while(l1 != NULL && l2 != NULL) { 
            int val = l1->val + l2->val + carry;
            
            carry = val / 10;
            l1->val = val % 10;
            l2->val = val % 10;
            
            prev_l1 = l1;
            prev_l2 = l2;
            l1 = l1->next;
            l2 = l2->next;
        }
        
        ListNode *prev;
        ListNode* result; 
        if(l1 != NULL) {
            result = l1_start;
            prev = prev_l1;
        }
        else {
            prev = prev_l2;
            result = l2_start;
        }
        ret = result;
        
        while(l1 != NULL) {
            int val = l1->val + carry;
            
            carry = val / 10;
            l1->val = val % 10;
            
            prev = l1;
            l1 = l1->next;
        }
        while(l2 != NULL) {
            int val = l2->val + carry;
            
            carry = val / 10;
            l2->val = val % 10;
            
            prev = l2;
            l2 = l2->next;
        }
        if(carry) {
            prev->next = new ListNode(carry);
        }
        
        return ret;
    }
};