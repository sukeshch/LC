class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> result;
        vector<vector<int>> grp_counts(groupSizes.size() + 1);
        for(int i=0; i< groupSizes.size(); i++) {
            grp_counts[groupSizes[i]].push_back(i);
            
            if(grp_counts[groupSizes[i]].size() == groupSizes[i]) {
                result.push_back(grp_counts[groupSizes[i]]);
                grp_counts[groupSizes[i]] = {};
            }
        }
        
        return result;
    }
};