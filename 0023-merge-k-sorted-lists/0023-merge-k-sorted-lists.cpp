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
    ListNode* Merge2(ListNode* l, ListNode* r)
    {
        ListNode* root = new ListNode(-1);
        
        ListNode *prev = root;
        while(l && r)
        {
            if(l->val < r->val)
            {
                prev->next = l;
                l = l->next;
            }
            else
            {
                prev->next = r;
                r = r->next;
            }
            prev = prev->next;
        }
        prev->next = (l) ? l : r;
        return root->next;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        ListNode *res = NULL;
        for(int i=0; i<lists.size(); i++)
        {
            res = Merge2(res, lists[i]);
        }
        return res;
    }
};