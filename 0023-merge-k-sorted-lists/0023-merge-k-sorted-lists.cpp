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
        if(lists.size() == 0) return NULL;
        // for(int i=0; i<lists.size(); i++)
        // {
        //     lists[0] = Merge2(lists[0], lists[i]);
        // }
        int len = 1;
        while(len < lists.size())
        {
            for(int i=0; (i+len) < lists.size(); i+=2*len)
            {
                lists[i] = Merge2(lists[i], lists[i+len]);
            }
            len*=2;
        }
        return lists[0];
    }
};