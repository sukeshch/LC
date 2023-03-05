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
        if(nums.empty()) return 0;
        vector<int> sum(nums.size() + 2, 0);
        // return recurse(nums, 0, sum);
        sum[nums.size()] = 0;
        sum[nums.size()-1] = nums.back();
        for(int i=nums.size()-2; i>=0; i--) {
            sum[i] = max(sum[i+1], nums[i] + sum[i+2]);
        }
        return sum[0];
    }
};