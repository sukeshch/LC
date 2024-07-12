class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> result(nums.size(), 0);
        int sz = nums.size();
        
        int sum = 0;
        for(int i=0; i<sz; i++) {
            sum += nums[i];
            result[i] = sum;
        }
        
        return result;
    }
};