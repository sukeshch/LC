class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> lossmp_;
        for(auto m : matches) {
            lossmp_[m[0]] = lossmp_[m[0]];
            lossmp_[m[1]]++;
        }
        vector<vector<int>> result(2, vector<int>());
        for(auto v : lossmp_) {
            if(v.second == 0)
                result[0].push_back(v.first);
            else if(v.second == 1)
                result[1].push_back(v.first);
        }
        return result;
    }
};