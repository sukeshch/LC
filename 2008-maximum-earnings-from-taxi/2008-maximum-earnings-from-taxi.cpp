class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        std::sort(rides.begin(), rides.end());
        vector<long long> dp(n + 1, 0);
        long long max_till_now = 0;
        
        int cride = rides.size()-1;
        for(int i=n; i>=1 && cride >= 0 ; i--) {
            if(rides[cride][0] == i) { // if start matches with i
                while(cride >= 0 && rides[cride][0] == i) {
                    long long st = rides[cride][0],
                        end = rides[cride][1],
                        tip = rides[cride][2];
                    dp[i] = max(dp[i], 
                                end - st + tip + dp[end]);
                    cride--;
                }
                max_till_now = max(max_till_now, dp[i]);
            } 
            dp[i] = max_till_now;
        }
        return max_till_now;
    }
};