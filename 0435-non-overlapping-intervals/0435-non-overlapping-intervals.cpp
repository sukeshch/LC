class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int result = 0;
        sort(intervals.begin(), intervals.end(), [](auto a, auto b){
            return a[1] < b[1];
            });
        // for(auto i : intervals) {
        //     printf("[%d, %d] ", i[0], i[1]);
        // }
        
        int max_end = INT_MIN; // max end seen and valid till now
        for(int i = 0; i < intervals.size(); i++) {
            int c[2] = {intervals[i][0], intervals[i][1]}; // curr interval
            if(
                c[0] < max_end
            ) { // overlap
                result++;
            } 
            else {
                max_end = c[1];
            }
        }
        
        return result;
    }
};