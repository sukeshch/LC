class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<pair<int,int>> db;
        for(auto v : intervals) {
            db.push_back({v[0], v[1]});
        }
        std::sort(db.begin(), db.end());
        pair<int, int> prev(db[0]);
        vector<vector<int>> result;
        result.push_back({prev.first, prev.second});
        for(int i=1; i<db.size(); i++)
        {
            // db[i].first is >= pre[]
            if(prev.second >= db[i].first)
            {
                result.back() = {prev.first, max(prev.second, db[i].second)};
                prev = {prev.first, max(prev.second, db[i].second)};
            }
            else
            {
                prev = db[i];
                result.push_back({prev.first, prev.second});
            }
        }
        return result;
    }
};