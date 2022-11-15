class Solution {
public:
    inline string GetFormattedString(int lower, int upper)
    {
        return to_string(lower) + ((upper-lower >= 1) ? ("->"+to_string(upper)) : "");
    }
    
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;
        if(nums.size() == 0) return {GetFormattedString(lower, upper)};
        int current_low = lower;
        for(int i = 0; i< nums.size(); i++)
        {
            if(nums[i] < lower) continue;
            if(nums[i] > upper) break; // pending add last range 
            if(current_low < nums[i])
            {
                result.push_back(GetFormattedString(current_low, nums[i]-1));
            }
            current_low = nums[i]+1;
        }
        if(current_low <= upper)
            result.push_back(GetFormattedString(current_low, upper));
        return result;
    }
};