class Solution {
public:
    void recurse(vector<int> curr, vector<vector<int>>& r, int sum, vector<int>& candidates, int currID)
    {
        for(int i=currID; i<candidates.size(); i++)
        {
            if(sum < candidates[i])
                break;
            else if(sum == candidates[i])
            {
                curr.push_back(candidates[i]);
                r.push_back(curr);
                return;
            }
            auto temp = curr;
            temp.push_back(candidates[i]);
            recurse(temp, r, sum-candidates[i], candidates, i);
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        vector<vector<int>> result;
        vector<int> temp;
        recurse(temp, result, target, candidates, 0);
        return result;
    }
};