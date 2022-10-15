class Solution {
public:
    void recurse(vector<int> nums, int index, vector<vector<int>> &result)
    {
        if(nums.size() == index)
        {
            result.push_back(nums);
            return;
        }
        for(int i= index; i<nums.size(); i++)
        {
            vector<int> temp = nums;
            swap(temp[index], temp[i]);
            recurse(temp, index+1, result);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        recurse(nums, 0, result);
        return result;
    }
};