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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* root = new ListNode(-1);
        
        ListNode* prev = root;
        while(list1 || list2)
        {
            if(list1 && list2)
            {
                if(list2->val < list1->val)
                {
                    prev->next = list2;
                    prev = prev->next;
                    list2 = list2->next;
                } 
                else 
                {
                    prev->next = list1;
                    prev = prev->next;
                    list1 = list1->next;
                }
            }
            else 
            {
                while(list1)
                {
                    prev->next = list1;
                    return root->next;
                }
                while(list2)
                {
                    prev->next = list2;
                    return root->next;
                }
            }
        }
        return root->next;
    }
};