class Solution {
public:
    void backtrack(vector<int> &curr, vector<int> &nums, bitset<6> &b, vector<vector<int>> &result)
    {
        if(curr.size() == nums.size()) {
            result.push_back(curr);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(!b.test(i)) {
                b.set(i);
                curr.push_back(nums[i]);
                backtrack(curr, nums, b, result);
                curr.pop_back();
                b.reset(i);
            }
        }
        
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        bitset<6> b(0);
        backtrack(curr, nums, b, result);
        return result;
    }
};