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
    
    
    int maxProfit(vector<int>& prices) {
        dp = vector<vector<int>>(2, vector<int>(prices.size(), -1));
        
        return recurse(prices, 0, true);
    }
};