class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& ni) {
        if(intervals.size() == 0) 
            return {ni};
        
        vector<vector<int>> result;
        bool isInserted = false;
        int i=0;
        int ni_st = ni[0], ni_end = ni[1];
        while(i < intervals.size()) {
            int st = intervals[i][0], end = intervals[i][1];
            if (end < ni_st) {
                result.push_back(intervals[i]);
                i++;
                continue;
            }
            if(ni_end < st) {
                if(!isInserted) {
                    isInserted = true;
                    result.push_back(ni);
                }
                result.push_back(intervals[i]);
                i++;
                continue;
            }
            // overlapping case
            isInserted = true;
            int m_st = min(st, ni_st), m_end = max(end, ni_end);
            while (i < intervals.size() && m_end >= intervals[i][0]) {
                m_end = max(m_end, intervals[i][1]);
                i++;
            }
            result.push_back({m_st, m_end});
        }
        if(!isInserted)
            result.push_back(ni);
        return result;
    }
};