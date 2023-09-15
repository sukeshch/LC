class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int cur_len = 1, max_len = 1;
        map<int, int> mp_;
        for(auto n : nums)
            mp_[n]++;
        
        auto it = mp_.begin();
        
        it++;
        while(it != mp_.end()) {
            if(it->first == (prev(it)->first + 1)) {
                cur_len ++;
                max_len = max(max_len, cur_len);
            } else {
                cur_len = 1;
            }
            it++;
        }
        
        return max_len;
    }
};