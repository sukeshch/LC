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
    void reorderList(ListNode* head) {
        stack<ListNode*> st;
        deque<ListNode*> dq;
        
        ListNode* curr = head;
        while(curr) {
            dq.push_back(curr);
            curr = curr->next;
        }
        
        while(dq.size()  > 1) {
            auto front = dq.front();
            auto end = dq.back();
            front->next = end;
            dq.pop_front();
            dq.pop_back();
            if(!dq.empty()) {
                end->next = dq.front();
            } else {
                end->next = NULL;
            }
        }
        if(!dq.empty())
            dq.front()->next = NULL;
        
    }
};