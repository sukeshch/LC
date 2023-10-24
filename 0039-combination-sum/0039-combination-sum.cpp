class Solution {
    int target;
    vector<int> candidates;
    vector<vector<int>> result;
public:
    
    void recurse(int sum, int cur_index, vector<int>& curr) {
        if(sum == target) {
            result.push_back(curr);
            return;
        }
        if(sum > target){
            return;
        }
        
        for(int i=cur_index; i<candidates.size(); i++) {
            curr.push_back(candidates[i]);
            recurse(sum+candidates[i], i, curr);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& c, int t) {
        target = t;
        candidates = c;
        vector<int> curr;
        recurse(0, 0, curr);
        return result;
    }
};