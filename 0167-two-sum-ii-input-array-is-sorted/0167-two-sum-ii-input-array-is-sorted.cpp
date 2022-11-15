class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for(int i=0; i< nums.size(); i++)
        {
            if(mp.count(target-nums[i]) != 0 && i != mp[target-nums[i]]) 
            {
                return {mp[target-nums[i]]+1, i+1};
            }
            mp[nums[i]] = i;
        }
        return {};
    }
};