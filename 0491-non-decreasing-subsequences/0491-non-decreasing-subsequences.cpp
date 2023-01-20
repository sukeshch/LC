class Solution {
public:
    void generate(vector<vector<int>> &result, int index, vector<int>& nums) {
        if(index == nums.size()) return;
        for(int i = 0, sz = result.size(); i < sz; i++)
        {
            auto t = result[i];
            if(t.back() <= nums[index]) {
                t.push_back(nums[index]);
                result.push_back(t);
            }
        }
        result.push_back({nums[index]});
        generate(result, index+1, nums);
    }
    
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> result;
        // result.push_back({nums[0]});
        generate(result, 0, nums);
        set<vector<int>> res;
        for (auto r : result)
            if(r.size() > 1) res.insert(r);
        vector<vector<int>> out;
        for (auto r : res)
            out.push_back(r);
        return out; 
    }
};