class Solution {
public:
    int score(vector<int>& nums, int s, int e, vector<vector<int>> &dp) {
        if(dp[s][e] != -1)
            return dp[s][e];
        if(s==e) return nums[s];
        int val1 = nums[s] - score(nums, s+1, e, dp);
        int val2 = nums[e] - score(nums, s, e-1, dp);
        dp[s][e] = max(val1, val2);
        return dp[s][e];
    }
    
    bool predictTheWinner(vector<int>& nums) {
        int N = nums.size();
        vector<vector<int>> dp(N, vector<int>(N,-1));
        return score(nums, 0, N-1, dp) >= 0;
    }
};