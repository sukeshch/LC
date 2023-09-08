class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long sum = 0;
        for(auto n : nums)
            sum += n;
        
        return ((nums.size() * (nums.size() + 1)) / 2) - sum;
    }
};