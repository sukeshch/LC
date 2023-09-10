class Solution {
public:
//     int recurse(vector<int>& nums, int cur_sum) {
        
//     }
    vector<int> dp;
    
    int combinationSum4(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        if(target == 0)
            return 0;
        if(dp.size() == 0)
            dp = vector<int>(1001, -1);
        else if(dp[target] != -1) 
            return dp[target];
        int count = 0;
        for(int i=0; i < nums.size(); i++) {
            if(nums[i] == target) {
                count ++;
            } else if (nums[i] < target) {
                count += combinationSum4(nums, target - nums[i]);
            }
        }
        return dp[target] = count;
    }
};