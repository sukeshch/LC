class Solution {
public:
    int findMin(vector<int>& nums) {
        int index = 0;
        
        while(index < nums.size()-1 && nums[index] < nums[index + 1]) {
            index++;
        }
        if(index >= (nums.size()-1)) return nums[0];
        return nums[index + 1];
     }
};