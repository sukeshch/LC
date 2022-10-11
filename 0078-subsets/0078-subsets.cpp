class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        // a S1, a 
        int sz = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            sz = result.size();
            for(int k = 0; k < sz; k++)
            {
                auto temp = result[k];
                temp.push_back(nums[i]);
                result.push_back(temp);
            }
            vector<int> c(1,nums[i]);
            result.push_back(c);
        }
        vector<int> c;
        result.push_back(c);
        return result;
    }
};