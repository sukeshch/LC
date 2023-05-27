class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> result;
        vector<bool> found(nums.size() + 1);
        for(auto num : nums)
        {
            if(found[num])
                result.push_back(num);
            found[num] = true;
        }
        return result;
    }
};