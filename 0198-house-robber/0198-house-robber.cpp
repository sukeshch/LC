class Solution {
public:
    int recurse(vector<int>& nums, int index, vector<int>& sum) {
        if(index >= nums.size()) {
            return 0;
        }
        sum[index] = max(
            nums[index] + (sum[index+2] == -1 ? recurse(nums, index+2, sum) : sum[index+2]),
            (sum[index+1] == -1 ? recurse(nums, index+1, sum) : sum[index+1])
        );
        return sum[index];
    }
    
    int rob(vector<int>& nums) {
        vector<int> sum(nums.size() + 2, -1);
        return recurse(nums, 0, sum);
    }
};