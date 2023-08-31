class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long res = 0;
        int N = nums.size();
        int cur_max = nums.back();
        for(int i=N-2; i >=0 ; i--) {
            if(nums[i] <= cur_max) {
                // non decreasing
                cur_max = nums[i];
            } else {
                int numsplits = ceil(nums[i] * 1.0 / cur_max);
                res += numsplits - 1;
                cur_max = nums[i] / numsplits;
            }
        }
        return res;
    }
};