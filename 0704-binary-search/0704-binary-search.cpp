class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        if(nums[low] == target) return low;
        if(nums[high] == target) return high;
        
        while(low < high) {
            int mid = (low + high) / 2;
            if(nums[mid] == target) return mid;
            if(nums[mid] > target) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        if(nums[low] == target) return low;
        return -1;
    }
};