class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int index = 0;
        while(index + 1 < intervals.size()) {
            if(intervals[index+1][0] < intervals[index][1])
                return false;
            index++;
        }
        return true;
    }
};