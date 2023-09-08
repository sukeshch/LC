class Solution {
public:
    // bool canJump(vector<int>& nums) {
    //     // DP - O(n^2)
    //     int N = nums.size();
    //     vector<bool> dp = vector<bool>(nums.size() + 1, 0);
    //     dp[N-1] = true;
    //     for(int i = N-2; i >=0 ; i--) {
    //         bool canreach = false;
    //         for(int j = i; j <= i + nums[i] && i < N; j++) {
    //             canreach = dp[j];
    //             if(canreach)
    //                 break;
    //         }
    //         dp[i] = canreach;
    //     }
    //     return dp[0];
    // }
    
    bool canJump(vector<int>& nums) {
        int cur_max = 0;
        int N = nums.size();
        int i = 0;
        while(i < N) {
            if(i > cur_max)
                return false;
            
            cur_max = max(cur_max, i + nums[i]);
            
            if(cur_max == N-1) 
                return true;
            i++;
        }
        
        return (cur_max >= (nums.size()-1));
    }
};