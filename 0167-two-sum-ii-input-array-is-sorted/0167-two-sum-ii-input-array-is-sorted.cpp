class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // unordered_map<int, int> mp;
        // for(int i=0; i< nums.size(); i++)
        // {
        //     if(mp.count(target-nums[i]) != 0 && i != mp[target-nums[i]]) 
        //     {
        //         return {mp[target-nums[i]]+1, i+1};
        //     }
        //     mp[nums[i]] = i;
        // }
        // return {};
        
        // auto lower = std::lower_bound(nums.begin(), nums.end(), target+1);
        int l = 0, r = nums.size()-1;
        // std::cout << "r " << r << endl;
        // if(r == nums.size()) r = nums.size()-1;
        while(l <= r)
        {
            if(nums[l] + nums[r] == target)
                return {l+1, r+1};
            else if(nums[l]+nums[r] > target)
                r--;
            else 
                l++;
        }
        return {};
    }
};