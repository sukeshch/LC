class Solution {
public:
    inline string GetFormattedString(int lower, int upper)
    {
        if(upper == lower)
            return to_string(lower);
        return to_string(lower) + "->" + to_string(upper);
    }
    
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;
        if(nums.size() == 0) return {GetFormattedString(lower, upper)};
        int prev = lower;
        for(int i = 0; i< nums.size(); i++)
        {
            if(prev < nums[i])
                result.push_back(GetFormattedString(prev, nums[i]-1));
            prev = nums[i]+1;
        }
        if(prev <= upper)
            result.push_back(GetFormattedString(prev, upper));
        return result;
    }
};