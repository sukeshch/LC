class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<int, vector<int>, greater<int>> pq;
        std::sort(events.begin(), events.end());
        int cnt = 0;
        int prev_st = -1;
        int i = 0;
        while(i < events.size() || pq.size()) {
            if (pq.size() == 0)
                prev_st = events[i][0];
            
            while(i < events.size() && events[i][0] == prev_st) {
                pq.push(events[i++][1]); // pushing end date
            }
            
            cnt++;
            prev_st++;
            pq.pop();
            while(pq.size()>0 && pq.top() < prev_st)
                pq.pop();
        }
        return cnt;
    }
};