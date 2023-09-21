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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = 0;
        ListNode* root = new ListNode();
        root->next = head;
        auto prev = root;
        
        auto cur = head;
        while(cur) {
            sz++;
            cur = cur->next;
            if (sz > n) {
                prev = prev->next;
            }
        }
        // if(prev == root) {
        //     return root->next->next;
        // }
        if(prev->next && prev->next->next)
            prev->next = prev->next->next;
        else 
            prev->next = NULL;
        return root->next;
    }
};