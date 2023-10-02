class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int start = 0, end = nums.size()-1;
        
        while(start < end) {
            if(nums[start] % 2 == 0) {
                start++;
                continue;
            }
            if(nums[end] % 2 == 1) {
                end--;
                continue;
            }
            swap(nums[start++], nums[end--]);
        }
        
        return nums;
    }
};