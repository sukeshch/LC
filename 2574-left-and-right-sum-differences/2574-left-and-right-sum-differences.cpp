class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int sum = std::reduce(nums.begin(), nums.end());
        vector<int> result(nums.size(), 0);
        int left = 0, right = sum;
        for(int i=0; i<nums.size(); i++) {
            right -= nums[i];
            result[i] = abs(left - right);
            left += nums[i];
        }
        return result;
    }
};