class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());
        std::priority_queue<int, vector<int>, greater<int>> pq; // min heap of end times
        int cur_idx = 0;
        int max_rooms = 0;
        
        for(int i=0; i<=1000000 && cur_idx < intervals.size(); i++) {
            while(!pq.empty() && i >= pq.top()) { // top event does not overlap
                pq.pop();
            }
            while (cur_idx < intervals.size() && intervals[cur_idx][0] == i) {
                pq.push(intervals[cur_idx][1]); // push end time
                cur_idx++;
            }
            max_rooms = max(max_rooms, static_cast<int>(pq.size()) );
        }
        
        return max_rooms;
    }
};