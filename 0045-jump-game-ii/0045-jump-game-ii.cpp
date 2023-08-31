class Solution {
public:
    int recurse(vector<int>& nums, int index, vector<int> &dp) {
        if(dp[index] != -1) {
            return dp[index];
        }
        if(nums[index] == 0) {
            return dp[index] = 10000;
        }
        if(index + nums[index] >= nums.size() - 1) {
            return 1;
        }
        int min_st = 10001;
        for(int i = 1; i <= nums[index] && (index + i < nums.size()); i++) {
            int res = recurse(nums, index + i, dp);
            if(res < min_st) {
                min_st = res;
            }
        }
        return dp[index] = min_st + 1;
    }
    
    // int jump(vector<int>& nums) {
    //     vector<int> dp(nums.size(), -1);
    //     if(nums.size() == 1) {
    //         return 0;
    //     }
    //     return recurse(nums, 0, dp);
    // }
    
    int jump(vector<int>& nums) {
        int curEnd = 0, curFar = 0;
        int result = 0;
        for(int i=0; i < nums.size()-1; i++) {
            curFar = max(curFar, i + nums[i]);
            // if(curFar > nums.size() - 1) {
            //     break;
            // }
            if(i == curEnd) {
                result++;
                curEnd = curFar;
            }
        }
        return result;
    }
};