class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> jumps(n+1, -1);
        int start = 0, end = 0;
        for(int i=0; i< ranges.size(); i++) {
            start = max(0, i - ranges[i]);
            end = min(n, i + ranges[i]);
            
            jumps[start] = max(jumps[start], end);
        }
        
        // this becomes jump problem 
        int curEnd = 0, curFar = 0;
        int res = 0;
        for(int i = 0; i < ranges.size(); i++) {
            if(i > curFar) return -1;
            if(i > curEnd) {
                curEnd = curFar;
                res++;
            }
            curFar = max(curFar, jumps[i]);
        }
        // std::cout << "final curFar " << curFar << ", curEnd " << curEnd << endl;
        
        return res;
    }
};