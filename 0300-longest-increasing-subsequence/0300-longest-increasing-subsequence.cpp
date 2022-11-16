class Solution {
public:
    int recurse(vector<int>& nums, vector<int> &dp, int index, int prev)
    {
        if(index == nums.size()) return 0;
        int ans = 0;
        // if(dp[index] != -1)
        //     return dp[index];
        
        if(prev < nums[index]){
            ans = max(
                    1 + recurse(nums, dp, index+1, nums[index]), 
                    recurse(nums, dp, index+1, prev));
        } else 
            ans = recurse(nums, dp, index+1, prev);
        
        return ans;
    }
    
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int result = 1;
        for(int i=0; i<nums.size(); i++)
        {
            for(int j=0; j < i; j++)
            {
                if(nums[i] > nums[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                    result = max(result, dp[i]);
                }
            }
        }
        return result;
    }
};