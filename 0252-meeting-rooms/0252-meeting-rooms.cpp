class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.size() == 1) return true;
        auto v = intervals;
        std::sort(v.begin(), v.end());
        for(int i=1; i<v.size(); i++) {
            if(v[i-1][1] > v[i][0])
                return false;
        }
        return true;
    }
};