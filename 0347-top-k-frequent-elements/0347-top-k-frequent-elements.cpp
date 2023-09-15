class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> counts;
        for(auto n : nums)
            counts[n]++;
        priority_queue<pair<int,int>> pq;
        for(auto p : counts) {
            pq.push({-p.second, p.first});
            if(pq.size() > k)
                pq.pop();
        }
        vector<int> ans;
        pair<int,int> top;
        while(!pq.empty()) {
            top = pq.top();
            ans.push_back(top.second);
            pq.pop();
        }
        return ans;
    }
};