class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        /*
        // counts - O( N logN )
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
        */
        unordered_map<int,int> cnts_map;
        for(auto num : nums)
            cnts_map[num]++;
        auto comp = [&cnts_map](int n1, int n2) {return cnts_map[n1] < cnts_map[n2];};
        priority_queue<int, vector<int>, decltype(comp)> heap(comp);
        for(auto kv : cnts_map)
        {
            heap.push(kv.first);
        }
        vector<int> result;
        for(int i=0; i<k; i++){
            result.push_back(heap.top());
            heap.pop();
        }
        return result;
    }
};