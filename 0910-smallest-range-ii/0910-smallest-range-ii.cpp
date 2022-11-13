class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        
        int diffMax = nums.back() - nums[0];
        for(int i=1; i<nums.size(); i++)
        {
            diffMax = std::min(
                std::max(nums.back() - k, nums[i-1] + k) - 
                std::min(nums[0]     + k, nums[i] - k),
                diffMax
            );
        }
        return diffMax;
    }
};