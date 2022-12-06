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
        if(!head) return NULL;
        
        ListNode* oddHead = new ListNode(), *evenHead = new ListNode();
        oddHead->next = head;
        evenHead->next = head->next;
        
        ListNode* even = evenHead->next;
        ListNode* odd = oddHead->next;
        
        while(even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead->next;
        
//         while(head) {
//             ListNode *temp = head->next;
//             if(count % 2 == 1) {
//                 prev->next = head->next;
//                 even->next = head;
//                 even->next->next = NULL;
//                 even = even->next;
//             } else {
//                 last_odd = head;
//             }
            
//             prev = head;
//             head = temp;
//             count++;
//         }
//         if(last_odd)
//             last_odd->next = even_start->next;
        
        return head;
    }
};