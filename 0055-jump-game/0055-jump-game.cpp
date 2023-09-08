class Solution {
public:
    bool canJump(vector<int>& nums) {
        int N = nums.size();
        vector<bool> dp = vector<bool>(nums.size() + 1, 0);
        dp[N-1] = true;
        for(int i = N-2; i >=0 ; i--) {
            bool canreach = false;
            for(int j = i; j <= i + nums[i] && i < N; j++) {
                canreach = dp[j];
                if(canreach)
                    break;
            }
            dp[i] = canreach;
        }
        return dp[0];
    }
};