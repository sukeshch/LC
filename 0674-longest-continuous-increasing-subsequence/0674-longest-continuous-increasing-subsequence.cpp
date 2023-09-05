class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int start = 0, curr = start + 1;
        int lcis = 1;
        while(curr < nums.size()) {
            if(nums[curr-1] >= nums[curr]) {
                start = curr;
            }
            lcis = max(lcis, curr - start + 1);
            curr++;
        }
        return lcis;
    }
};