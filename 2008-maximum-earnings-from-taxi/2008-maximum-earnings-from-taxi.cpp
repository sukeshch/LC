class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        std::sort(rides.begin(), rides.end());
        vector<long long> dp(n + 2, 0);
        
        int cride = rides.size()-1;
        int i=n;
        long long res = 0;
        for(; i>=1 && cride >= 0 ; i--) {
            if(rides[cride][0] == i) { // if start matches with i
                while(cride >= 0 && rides[cride][0] == i) {
                    long long st = rides[cride][0],
                        end = rides[cride][1],
                        tip = rides[cride][2];
                    dp[i] = max(dp[i], 
                                end - st + tip + dp[end]);
                    cride--;
                }
            } 
            dp[i] = max(dp[i+1], dp[i]);
            res = max(dp[i], res);
        }
        return res;
    }
};