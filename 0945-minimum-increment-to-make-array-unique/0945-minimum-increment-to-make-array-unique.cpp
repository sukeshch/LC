class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        // int prev = nums[0];
        // int result = 0;
        // for(int i=1; i<nums.size(); i++)
        // {
        //     if(prev >= nums[i]) {
        //         result += (prev - nums[i] + 1);
        //         prev++;
        //     }
        //     else prev = nums[i];
        // }
        nums.push_back(nums[nums.size()-1] + nums.size());
        int result = 0, taken = 0;
        // int result = 0;
        int give;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i-1] == nums[i])
            {
                taken += 1;
                result -= nums[i];
            }
            else 
            {
                give = min(taken, nums[i]-nums[i-1]-1);
                result += (give * (give + 1) /2) + (give *nums[i-1]);
                taken -= give;
            }
        }
        return result;
    }
};