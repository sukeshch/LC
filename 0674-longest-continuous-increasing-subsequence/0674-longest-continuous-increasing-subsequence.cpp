class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int start = 0, curr = start + 1;
        int lcis = 1;
        while(curr < nums.size()) {
            if(nums[curr] > nums[curr-1]) {
                lcis = max(lcis, curr - start + 1);
            } else {
                start = curr;
            }
            curr++;
        }
        lcis = max(lcis, curr - start);
        return lcis;
    }
};