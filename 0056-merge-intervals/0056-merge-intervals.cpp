class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        for(auto intr : intervals) {
            if(result.empty()) 
                result.push_back(intr);
            else if (intr[0] <= result.back()[1]) {
                result.back()[1] = max(result.back()[1], intr[1]);
            } else {
                result.push_back(intr);
            }
        }
        return result;
    }
};