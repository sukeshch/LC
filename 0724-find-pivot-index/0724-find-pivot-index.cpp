class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector<int> left_sum(nums.size(), 0), right_sum(nums.size(), 0);
        
        for(int i = 1; i < nums.size(); i++ ) {
            left_sum[i] = left_sum[i-1] + nums[i-1];
        }
        
        for(int i = nums.size()-2; i >= 0; i-- ) {
            right_sum[i] = right_sum[i+1] + nums[i+1];
        }
        if (right_sum[0] == 0) {
            return 0;
        }
        
        for(int i = 1; i < nums.size()-1; i++) {
            if(left_sum[i] == right_sum[i]) {
                return i;
            }
        }
        
        if(left_sum[nums.size() - 1] == 0) {
            return nums.size()-1;
        }
        
        return -1;
    }
};