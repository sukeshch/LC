class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int prev = nums[0];
        int result = 0;
        for(int i=1; i<nums.size(); i++)
        {
            // cout << "prev " << prev << " c " << nums[i] << " " << result << endl;
            if(prev >= nums[i])
            {
                result += (prev - nums[i] + 1);
                prev++;
            }
            else prev = nums[i];
        }
        return result;
    }
};