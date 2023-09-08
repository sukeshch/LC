class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        {
            bool all_negative = true;
            int max_negative = INT_MIN;
            for(auto num : nums) {
                if(num >= 0) {
                    all_negative = false;
                    break;
                }
                max_negative = max(max_negative, 
                                   num);
            }
            if(all_negative)
                return max_negative;
        }
        
        int cur_sum = 0, max_sum = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(cur_sum < 0) {
                cur_sum = 0;
            }
            cur_sum += nums[i];
            
            max_sum = max(cur_sum, max_sum);
        }
        
        return max_sum; 
    }
};