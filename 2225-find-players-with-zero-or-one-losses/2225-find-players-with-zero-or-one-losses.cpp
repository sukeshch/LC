class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, pair<int, int>> mp_;
        for(auto m : matches) {
            mp_[m[0]].first++;
            mp_[m[1]].second++;
        }
        vector<vector<int>> result(2, vector<int>());
        for(auto v : mp_) {
            if(v.second.second == 0)
                result[0].push_back(v.first);
            if(v.second.second == 1)
                result[1].push_back(v.first);
        }
        return result;
    }
};