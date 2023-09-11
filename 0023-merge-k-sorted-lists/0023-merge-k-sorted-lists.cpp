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
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> cur_indexes(lists.size());
        
        for(int i=0; i<lists.size(); i++) {
            cur_indexes[i] = lists[i];
            if(cur_indexes[i]) {
                pq.push({cur_indexes[i]->val, i});
            }
        }
        ListNode* result = new ListNode();
        ListNode *curr = result;
        while (!pq.empty()) {
            auto t = pq.top();
            pq.pop();
            int l_idx = t.second;
            curr->next = cur_indexes[l_idx];
            curr = curr->next;
            cur_indexes[l_idx] = cur_indexes[l_idx]->next;
            if(cur_indexes[l_idx]) 
                pq.push({ cur_indexes[l_idx]->val, l_idx });
        }
        
        return result->next;
    }
};