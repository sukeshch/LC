class Solution {
public:
    int minOperations(vector<int>& nums) {
        int cur_min = nums[0];
        int res = 0;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] <= cur_min) {
                res += cur_min-nums[i]+1;
                cur_min ++;
            } 
            else {
                cur_min = nums[i];
            }
        }
        
        return res;
    }
};