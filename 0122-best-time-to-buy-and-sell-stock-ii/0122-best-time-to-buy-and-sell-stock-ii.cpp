class Solution {
public:
    vector<vector<int>> dp;
    
    int recurse(vector<int> &prices, int index, bool buy) {
        if(index == prices.size() - 1) {
            return dp[buy][index] = buy ? 0 : prices[index];
        }
        if(dp[buy][index] != -1) {
            return dp[buy][index];
        }
        int cur_max = recurse(prices, index + 1, buy);
        cur_max = max(cur_max, 
                    (buy ? -1 : 1) * prices[index] + recurse(prices, index + 1, !buy));
        
        return dp[buy][index] = cur_max;
    }
    
    
//     int maxProfit(vector<int>& prices) {
//         dp = vector<vector<int>>(2, vector<int>(prices.size(), -1));
        
//         return recurse(prices, 0, true);
//     }
    int maxProfit(vector<int>& prices) {
        int min_seen = prices[0];
        int index = 1;
        int ans = 0;
        
        while(index < prices.size()) {
            while(index < prices.size() && prices[index-1] > prices[index]) {
                min_seen = prices[index];
                index++;
            }
            int curmax = 0;
            while(index < prices.size() && prices[index-1] <= prices[index]) {
                curmax = max(curmax, prices[index] - min_seen);
                index++;
            }
            ans += curmax;
        }
        
        return ans;
    }
};