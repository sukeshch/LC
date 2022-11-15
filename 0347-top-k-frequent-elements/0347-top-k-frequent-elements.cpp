class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> counts;
        unordered_map<int, int> mp;
        for(auto num : nums)
        {
            mp[num]++;
        }
        for(auto v : mp)
        {
            counts.push_back(v.second);
        }
        std::sort(counts.begin(), counts.end());
        int minCount = counts[counts.size()-k];
        vector<int> result;
        for(auto v : mp)
        {
            if(v.second >= minCount) result.push_back(v.first);
        }
        return result;
    }
};