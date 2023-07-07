class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for(auto n: nums) sum += n;
        
        int left = 0, right = sum;
        int i = 0;
        while(i < nums.size()) {
            right -= nums[i];
            if(left == right)
                return i;
            left += nums[i];
            i++;
        }
        return -1;
    }
};