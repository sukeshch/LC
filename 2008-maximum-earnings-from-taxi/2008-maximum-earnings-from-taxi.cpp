class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        std::sort(rides.begin(), rides.end());
        vector<long long> dp(n + 2, 0);
        
        long long res = 0;
        for(int i=n, cride = rides.size()-1; i>=1 && cride >= 0 ; i--) {
            if(rides[cride][0] == i) { // if start matches with i
                while(cride >= 0 && rides[cride][0] == i) {
                    dp[i] = max(dp[i], 
                                static_cast<long long>(rides[cride][2] + 
                                rides[cride][1] - rides[cride][0] + 
                                dp[rides[cride][1]]));
                    cride--;
                }
            } 
            dp[i] = max(dp[i+1], dp[i]);
            res = max(dp[i], res);
        }
        return res;
    }
};