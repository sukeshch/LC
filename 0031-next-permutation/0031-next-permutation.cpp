class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int id = 0;
        for(int i=nums.size()-1; i>0; i--) {
            if(nums[i] > nums[i-1]) {
                id = i;
                break;
            }
        }
        if(id > 0) {
            int rightmost_index = id;
            while(rightmost_index < nums.size() && nums[id-1] < nums[rightmost_index]) {
                rightmost_index++;
            }
            swap(nums[id-1], nums[rightmost_index-1]);
        }
        reverse(nums.begin() + id, nums.end());
    }
};