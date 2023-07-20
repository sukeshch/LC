class Solution {
public:
    vector<vector<int>> result;
    void backtrack(vector<int> &curr, int sz, vector<int> &counters) {
        if(curr.size() == sz) {
            result.push_back(curr);
            return;
        }
        for(int i=0; i<counters.size(); i++) {
            if(counters[i]) {
                counters[i]--;
                curr.push_back(i-10);
                backtrack(curr, sz, counters);
                curr.pop_back();
                counters[i]++;
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> counters(21, 0);
        for(auto num : nums)
            counters[num+10]++;
        vector<int> curr;
        backtrack(curr, nums.size(), counters);
        return result;
    }
};