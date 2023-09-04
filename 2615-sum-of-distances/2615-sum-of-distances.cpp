class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        vector<long long> res(nums.size(), 0);
        unordered_map<int, vector<long long>> mp_;
        for(int i=0; i<nums.size(); i++) {
            mp_[nums[i]].push_back(i);      // first index
        }
        for(auto v : mp_) {
            if(v.second.size() <= 1) continue;
            // std::sort(v.second.begin(), v.second.end());
            std::vector<long long> prefixSum(v.second.size() + 1);
            prefixSum[0] = 0;
            prefixSum.back() = 0;
            int N = v.second.size();;
            // build prefix sum
            for(int i=0; i < N; i++) {
                prefixSum[i+1] = prefixSum[i] + v.second[i];
            }
            // use prefix sum to fill result
            for(int i=0; i < N; i++) {
                res[v.second[i]] = prefixSum.back() - prefixSum[i] - prefixSum[i+1] + v.second[i] * (2 * i - N + 1);
            }
        }
        return res;
    }
};