class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        // vector<bool> found(nums.size() + 1);
        for(auto num : nums)
        {
            if(nums[abs(num)-1] < 0)
                result.push_back(abs(num));
             
            nums[abs(num)-1]  = -1 * nums[abs(num)-1];
        }
        return result;
    }
};