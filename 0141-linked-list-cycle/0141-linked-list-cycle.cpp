/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *ptr = head, *ptr_2x = head;
        
        while(ptr && ptr_2x && ptr_2x->next) {
            ptr = ptr->next;
            ptr_2x = ptr_2x->next->next;
            if(ptr == ptr_2x) 
                return true;
        }
        return false;
    }
};