class Solution {
public:
    vector<vector<int>> result;
    void backtrack(vector<int> &curr, bitset<8> b, 
                   vector<int> &nums) {
        if(curr.size() == nums.size()) {
            result.push_back(curr);
            return;
        }
        int prev = -11;
        for(int i=0; i<nums.size(); i++) {
            if(!b.test(i) && prev != nums[i]) {
                b.set(i);
                curr.push_back(nums[i]);
                backtrack(curr, b, nums);
                curr.pop_back();
                b.reset(i);
                prev = nums[i];
            }
        }
    }
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        bitset<8> b(0);
        vector<int> curr;
        backtrack(curr, b, nums);
        return result;
    }
};