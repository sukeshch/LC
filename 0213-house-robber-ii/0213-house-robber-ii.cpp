class Solution {
public:
    int rob1(vector<int>& nums, int start, int sz) {
        vector<int> dp(sz+1, 0);
        dp[sz-1] = nums[sz-1];
        for(int i=sz-2; i>=start; i--) {
            dp[i] = max(dp[i+1], dp[i+2] + nums[i]);
        }
        return dp[start];
    }
    
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);
        return max(
            rob1(nums, 1, nums.size()),
            rob1(nums, 2, nums.size()-1) + nums[0]
                  );
    }
};