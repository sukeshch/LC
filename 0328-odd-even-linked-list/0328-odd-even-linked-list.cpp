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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* odd = new ListNode(), *even = new ListNode();
        odd->next = head;
        ListNode* even_start = even;
        ListNode* prev = odd;
        
        int count = 0;
        ListNode* last_odd = head;
        while(head) {
            ListNode *temp = head->next;
            if(count % 2 == 1) {
                prev->next = head->next;
                even->next = head;
                even->next->next = NULL;
                even = even->next;
            } else {
                last_odd = head;
            }
            
            prev = head;
            head = temp;
            count++;
        }
        if(last_odd)
            last_odd->next = even_start->next;
        
        return odd->next;
    }
};